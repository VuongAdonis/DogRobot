import can
import time
import struct

def initialCAN():
    # Stock slcan firmware on Linux
    bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
    return bus

def sendClosedLoop(bus, id):
    # Change the Odrive to state CLOSED_LOOP
    id_ = id<< 5 | 0x07
    msg = can.Message(arbitration_id=id_,
                data=[0x08, 0x00, 0x00, 0x00],
                  dlc= 4,
                  is_extended_id=False)
    bus.send(msg)
    print("Message sent state CLOSEDLOOP on {}".format(bus.channel_info))

def sendIdle(bus, id):
    # Change the Odrive to state IDLE
    id_ = id<<5 | 0x07
    msg = can.Message(arbitration_id=id_,
                  data=[0x01, 0x00, 0x00, 0x00],
                  dlc= 4,
                  is_extended_id=False)
    bus.send(msg)
    print("Message sent state IDLE on {}".format(bus.channel_info))

# The function convert from Float to Hex 
def convertFloatToHex(num:float):
    packed = struct.pack('<f', num)  # Pack as a little-endian float
    hexValue = packed.hex()
    byteArray = [hexValue[i:i+2] for i in range(0, len(hexValue), 2)]
    return byteArray

def sendPos(bus, id, pos:float):
    # Chaneg motor position
    # calculate array contain the byte of the position
    data_ = convertFloatToHex(pos)
    # in this case, we just want to send the position
    # so the data for vel and  torque will be 0
    byteVelTorque = convertFloatToHex(0)
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
    bus.send(msg)
    print("Message sent input_pos on {}".format(bus.channel_info))

# this function is used to convert data from byte hex to float
def getValuePos(data):
    pos = []
    for i in range(len(data)):
        if(len(pos) < 4):
            pos.append(data[i])
    reversed_bytes = bytes(pos)
    floatValue = struct.unpack('<f', bytes(reversed_bytes))[0]  # '<f' for float little-endian
    print(f"Giá trị float: {floatValue}")
    return floatValue

# This function is used to send the message 
# and return the position (estimate) of the Odrive
def sendGetEncoderEstimate(bus, id):
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
    bus.send(msg)
    print("Message sent closed loop on {}".format(bus.channel_info))

    isNotPosMsg = True
    while isNotPosMsg:
        response = bus.recv(timeout=1)  # Chờ phản hồi trong 1 giây
        if response:
        # Kiểm tra ID của phản hồi
            if response.arbitration_id == id_:
                isNotPosMsg = False
                # Giả sử phản hồi chứa dữ liệu cần thiết
                print(f"Phản hồi nhận được - ID: {response.arbitration_id}, Dữ liệu: {response.data.hex()}")
                pos = getValuePos(response.data)
                return pos
            else:
                print(f"ID CAN không mong đợi từ phản hồi: ID: {response.arbitration_id}, Dữ liệu: {response.data.hex()}")
        else:
            print("Không có phản hồi từ ODrive.")

def sendMessage(bus, id, pos=None):
    # CLOSED LOOP
    sendClosedLoop(bus, id)

    # IDLE
    sendIdle(bus, id)

    # pos
    sendPos(bus, id, pos)
    

def main(args=None):
    # bus = initialCAN()
    bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
    try:
        sendClosedLoop(bus, 1)
        sendPos(bus, 1, 2)
        count = 0
        while True:
            MotorPos = sendGetEncoderEstimate(bus, 1)
            if MotorPos > 1.99:
                print("Move the motor to the position 2 completed")
                sendPos(bus, 1, 0)
                count+=1
            if MotorPos < 0.1:
                print("Move the motor to the position 0 completed")
                sendPos(bus, 1, 2)
                count+=1
            if count >=5:
                break
        sendIdle(bus, 1)
        time.sleep(5)
    except can.CanError:
        print("Message NOT sent")

    finally:
        # Đảm bảo việc tắt bus đúng cách
        bus.shutdown()  # Hoặc sử dụng 'bus.close()' nếu có phương thức này

        print("SLCAN bus đã được tắt đúng cách.")

if __name__ == '__main__':
    main()