import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time

class Move(Node):
    def __init__(self):
        super().__init__('gamepad_recorder')
        self.subscription = self.create_subscription(
            String, # message type
            'joy', # topic
            self.joy_callback, # callback function
            10 # queue size
        )
        self.gamepad_values = []  # Danh sách lưu giá trị gamepad
        self.prev_time = time.time()
        self.count = 0
    
    def goStraight():
        pass

    def goBack():
        pass

    def goLeft():
        pass

    def goRight():
        pass

    def stand():
        pass

    def sitDown():
        pass

    def joy_callback(self, msg):
        self.current_time = time.time()
        
        if self.current_time - self.prev_time > 5:
            self.prev_time = self.current_time
            print("Value save: ", msg.buttons, msg.axes)
            print("print count: ", self.count)
            self.count += 1

def main():
    rclpy.init()

    dogMove = Move()

    try:
        # run rclpy.spin to process the event
        rclpy.spin(dogMove)
    except KeyboardInterrupt:
        dogMove.destroy_node()
        rclpy.shutdown()
        print("Stop completed")
        
if __name__ == '__main__':
    main()
