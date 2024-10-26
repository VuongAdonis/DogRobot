import can
import time
import struct
import rclpy
from rclpy.node import Node
from custom_interfaces.msg import PublishMessage

class CanNode(Node):
    def __init__(self):
        self.bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
        # self.sendClosedLoop(1)
        time.sleep(0.1)
        self.sendClosedLoop(3)
        time.sleep(0.1)
        self.sendClosedLoop(4)
        time.sleep(0.1)
        self.sendClosedLoop(5)
        time.sleep(0.1)


        print("All ODrives have been set to ClosedLoop")

        super().__init__("SubscriberNode")
        self.subscription = self.create_subscription(
            PublishMessage,
            'publishTopic',
            self.CAN_listen_callback,
            10
        )
        self.count = 0

    def StopSend(self):
        # self.sendIdle(1)
        # time.sleep(0.1)
        self.sendIdle(3)
        time.sleep(0.1)
        self.sendIdle(4)
        time.sleep(0.1)
        self.sendIdle(5)
        time.sleep(0.1)
        print("All ODrives have been set to Idle")
        
    # This function is used to process the position after get from the main control
    def CAN_listen_callback(self, msg):
        posRR = msg.positionrr
        posRL = msg.positionrl
        posFR = msg.positionfr
        posFL = msg.positionfl
        
        self.count += 1

        print("Message come: ", self.count)
        # print("posRR = ", posRR)
        # print("posRL = ", posRL)
        print("posFR = ", posFR)
        # print("posFL = ", posFL)


        # send message
        self.sendPos(5, posFR[2])
        time.sleep(0.005)
        self.sendPos(4, posFR[1])
        time.sleep(0.005)
        self.sendPos(3, posFR[0])
        time.sleep(0.005)



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
        print("Message sent input_pos on {}".format(self.bus.channel_info))

    # this function is used to convert data from byte hex to float
    def getValuePos(data):
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
        print("Message sent to get the position on {}".format(self.bus.channel_info))

        isNotPosMsg = True
        while isNotPosMsg:
            response = self.bus.recv(timeout=0.5)  # wait respond in 1 second
            if response:
            # Check Respond ID
                if response.arbitration_id == id_:
                    isNotPosMsg = False
                    print(f"Respond from  - ID: {response.arbitration_id}, data: {response.data.hex()}")
                    pos = self.getValuePos(response.data)
                    return pos
                else:
                    # value out of test from 0 - 2
                    return 100
                #     print(f"ID CAN wrong: ID: {response.arbitration_id}, Data: {response.data.hex()}")
            else:
                print("No respond from ODrive.")
    
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
        # run rclpy.spin to process the event
        rclpy.spin(robotDogHk241)
    except KeyboardInterrupt:
        robotDogHk241.StopSend()
        robotDogHk241.bus.shutdown() 
        print("SLCAN bus has been turned off properly.")
        robotDogHk241.destroy_node()
        rclpy.shutdown()
        print("Stop completed")


if __name__ == '__main__':
    main()