import can
import time
import struct
import rclpy
from rclpy.node import Node
from custom_interfaces.msg import PublishMessage
from custom_interfaces.srv import CANsrv
from enum import Enum
import os

class legRR(Enum):
	shoulder 	= 0
	thigh 		= 1
	shank		= 2

class legFR(Enum):
	shoulder 	= 3
	thigh 		= 4
	shank		= 5

class legRL(Enum):
	shoulder 	= 6
	thigh 		= 7
	shank		= 8

class legFL(Enum):
	shoulder 	= 9
	thigh 		= 10
	shank		= 11
     

class CanNode(Node):
    def __init__(self):
        # self.bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
        available_ports = self.find_available_acm_ports()
        for port in available_ports:
            self.bus = can.interface.Bus(bustype='slcan', channel=f'/dev/{port}', bitrate=500000)

            if self.bus:
                # Nếu kết nối thành công, bạn có thể thực hiện các hoạt động ở đây
                print("connect succeed to ", port)
                break


        self.timeDelayPos = 0.5
        self.sendClosedLoop(legRR.shoulder.value)
        time.sleep(0.1)
        self.sendClosedLoop(legRR.thigh.value)
        time.sleep(0.1)
        self.sendClosedLoop(legRR.shank.value)
        time.sleep(0.1)
        
        self.sendClosedLoop(legFR.shoulder.value)
        time.sleep(0.1)
        self.sendClosedLoop(legFR.thigh.value)
        time.sleep(0.1)
        self.sendClosedLoop(legFR.shank.value)
        time.sleep(0.1)

        self.sendClosedLoop(legRL.shoulder.value)
        time.sleep(0.1)
        self.sendClosedLoop(legRL.thigh.value)
        time.sleep(0.1)
        self.sendClosedLoop(legRL.shank.value)
        time.sleep(0.1)

        self.sendClosedLoop(legFL.shoulder.value)
        time.sleep(0.1)
        self.sendClosedLoop(legFL.thigh.value)
        time.sleep(0.1)
        self.sendClosedLoop(legFL.shank.value)
        time.sleep(0.1)


        print("All ODrives have been set to ClosedLoop")

        super().__init__("serviceCANNode")
        self.service = self.create_service(
            CANsrv,
            "cansrv",
            self.CAN_listen_callback
        )
        self.count = 0
        self.CheckCANDone = [0] * 12
        self.ODrivePos = [0] * 12
        self.CANDone = False
        self.shankID = [2, 5, 8, 11]

    def find_available_acm_ports(self):
        # Lấy danh sách tất cả các cổng ttyACM*
        ports = [f for f in os.listdir('/dev') if f.startswith('ttyACM')]
        return ports

    def StopSend(self):
        self.sendIdle(legRR.shoulder.value)
        time.sleep(0.1)
        self.sendIdle(legRR.thigh.value)
        time.sleep(0.1)
        self.sendIdle(legRR.shank.value)
        time.sleep(0.1)

        self.sendIdle(legFR.shoulder.value)
        time.sleep(0.1)
        self.sendIdle(legFR.thigh.value)
        time.sleep(0.1)
        self.sendIdle(legFR.shank.value)
        time.sleep(0.1)

        self.sendIdle(legRL.shoulder.value)
        time.sleep(0.1)
        self.sendIdle(legRL.thigh.value)
        time.sleep(0.1)
        self.sendIdle(legRL.shank.value)
        time.sleep(0.1)

        self.sendIdle(legFL.shoulder.value)
        time.sleep(0.1)
        self.sendIdle(legFL.thigh.value)
        time.sleep(0.1)
        self.sendIdle(legFL.shank.value)
        time.sleep(0.1)
        print("All ODrives have been set to Idle")
        
    # This function is used to process the position after get from the main control
    def CAN_listen_callback(self, request, response):
        self.get_logger().info(f"Incoming request\n")
        posRR = request.positionrr
        posRL = request.positionrl
        posFR = request.positionfr
        posFL = request.positionfl
        
        self.count += 1
        self.ODrivePos = posRR + posFR + posRL + posFL

        print("Message come: ", self.count)
        print("posRR = ", posRR)
        # print("posRL = ", posRL)
        # print("posFR = ", posFR)
        # print("posFL = ", posFL)


        # send message
        self.sendPos(legRR.shoulder.value, posRR[0])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legRR.thigh.value, posRR[1])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legRR.shank.value, posRR[2])
        # time.sleep(self.timeDelayPos)

        self.sendPos(legFR.shoulder.value, posFR[0])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legFR.thigh.value, posFR[1])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legFR.shank.value, posFR[2])
        # time.sleep(self.timeDelayPos)

        self.sendPos(legRL.shoulder.value, posRL[0])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legRL.thigh.value, posRL[1])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legRL.shank.value, posRL[2])
        # time.sleep(self.timeDelayPos)

        self.sendPos(legFL.shoulder.value, posFL[0])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legFL.thigh.value, posFL[1])
        # time.sleep(self.timeDelayPos)
        self.sendPos(legFL.shank.value, posFL[2])
        # time.sleep(self.timeDelayPos)

        # # Check encoder of ODrive
        self.CANDone = False
        timeStart = time.time()
        while not self.CANDone:
             timeLimit = time.time()
             if timeLimit - timeStart >= 0.2:
                 self.CheckCANDone = [0] * 12
                 break
             for index in range(0,12):
                if(self.CheckCANDone[index] != 1):
                    if index in self.shankID:
                        thresh_hold = 0.01
                    else:
                        thresh_hold = 0.1
                    encoder_pos = self.sendGetEncoderEstimate(index)
                    if  encoder_pos > self.ODrivePos[index] - thresh_hold and encoder_pos < self.ODrivePos[index] + thresh_hold:
                        self.CheckCANDone[index] = 1

             if all(x == 1 for x in self.CheckCANDone):
                self.CheckCANDone = [0] * 12
                self.CANDone = True
                print("pos: ", self.ODrivePos[2])
                self.ODrivePos = [0] * 12
                print("pos done")

        

        # Send the reponse to the Quadruped to notice that motor done.
        # time.sleep(0)
        response.can_done = True
        # time.sleep(1)
        return response


    def sendClosedLoop(self, id):
        # Change the Odrive to state CLOSED_LOOP
        id_ = id<< 5 | 0x07
        msg = can.Message(arbitration_id=id_,
                    data=[0x08, 0x00, 0x00, 0x00],
                    dlc= 4,
                    is_extended_id=False)
        self.bus.send(msg)
        print("Message sent state CLOSEDLOOP on {}".format(self.bus.channel_info))

    def sendIdle(self, id):
        # Change the Odrive to state IDLE
        id_ = id<<5 | 0x07
        msg = can.Message(arbitration_id=id_,
                    data=[0x01, 0x00, 0x00, 0x00],
                    dlc= 4,
                    is_extended_id=False)
        self.bus.send(msg)
        print("Message sent state IDLE on {}".format(self.bus.channel_info))

    # The function convert from Float to Hex 
    def convertFloatToHex(self, num:float):
        packed = struct.pack('<f', num)  # Pack as a little-endian float
        hexValue = packed.hex()
        byteArray = [hexValue[i:i+2] for i in range(0, len(hexValue), 2)]
        for index, byte in enumerate(byteArray):
            integer_value = int(byte, 16)
            byteArray[index] = integer_value
        return byteArray

    def sendPos(self, id, pos:float):
        # Chaneg motor position
        # calculate array contain the byte of the position
        data_ = self.convertFloatToHex(pos)
        # in this case, we just want to send the position
        # so the data for vel and  torque will be 0
        byteVelTorque = self.convertFloatToHex(0)
        # Append the array byteVelTorque to the data_
        for byte in byteVelTorque:
            data_.append(byte)
        print("the data: ", data_)
        id_ = id<<5 | 0x0C
        #create message and send

        msg = can.Message(arbitration_id=id_,
                    data=data_,
                    dlc= 8,
                    is_extended_id=False)
        self.bus.send(msg)
        print("Message sent input_pos on {}".format(id_))

    # this function is used to convert data from byte hex to float
    def getValuePos(self, data):
        pos = []
        for i in range(len(data)):
            if(len(pos) < 4):
                pos.append(data[i])
        reversed_bytes = bytes(pos)
        floatValue = struct.unpack('<f', bytes(reversed_bytes))[0]  # '<f' for float little-endian
        print(f"position: {floatValue}")
        return floatValue

    # This function is used to send the message 
    # and return the position (estimate) of the Odrive
    def sendGetEncoderEstimate(self, id):
        id_ = id<<5 | 0x09
        # This message used to get the position of Odrive
        # so the flag is_remote_frame must be True
        # and the data is full 0 in this case
        msg = can.Message(arbitration_id=id_,
                    data=[0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00],
                    dlc= 8,
                    is_extended_id=False,
                    is_remote_frame=True)
        
        # flush the buffer with
        while not (self.bus.recv(timeout=0) is None): pass

        self.bus.send(msg)
        print("Message sent to get the position on {}".format(id_))

        isNotPosMsg = True
        while isNotPosMsg:
            response = self.bus.recv(timeout=0.5)  # wait respond in 1 second
            if response:
            # Check Respond ID
                if response.arbitration_id == id_:
                    isNotPosMsg = False
                    print(f"Respond from  - ID: {response.arbitration_id}, data: {response.data.hex()}")
                    print("data: ", response.data)
                    pos = self.getValuePos(response.data)
                    return pos
                # else:
                #     # value out of test from 0 - 2
                #     return 100
                # #     print(f"ID CAN wrong: ID: {response.arbitration_id}, Data: {response.data.hex()}")
            else:
                print("No respond from ODrive.")
                return 0
    
    def sendPositionContinuously(self, id, point):
        try:
            i = 3
            while True:
                self.sendPos(id[0], point[i][0])
                self.sendPos(id[1], point[i][1])
                self.sendPos(id[2], point[i][2])
                i+=1
                if i > 7:
                    i = 0
                time.sleep(0.5)
        except KeyboardInterrupt:
            print("Message NOT sent")
            # Đảm bảo việc tắt bus đúng cách
            self.bus.shutdown()  # Hoặc sử dụng 'bus.close()' nếu có phương thức này

            print("SLCAN bus has been turned off properly.")

def main(args=None):
    # bus = initialCAN()
    # bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
    rclpy.init(args=args)
    robotDogHk241 = CanNode()
    try:
        while True:
            try:
                # run rclpy.spin to process the event
                rclpy.spin(robotDogHk241)
            except Exception as e:
                print(f"Có lỗi xảy ra: {e}")
                print("Reconect...")
                print("Shutdown the bus")
                robotDogHk241.destroy_node()
                robotDogHk241 = CanNode()
                print("Reconnect succeed...")
    except KeyboardInterrupt:
        print("Stop program")
    finally:
        robotDogHk241.StopSend()
        robotDogHk241.bus.shutdown() 
        print("SLCAN bus has been turned off properly.")
        robotDogHk241.destroy_node()
        # rclpy.shutdown()
        print("Stop completed")
    
if __name__ == '__main__':
    main()