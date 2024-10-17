import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
import subprocess
import time

class GamepadRecorder(Node):
    def __init__(self):
        super().__init__('gamepad_recorder')
        self.subscription = self.create_subscription(
            Joy, # message type
            'joy', # topic
            self.joy_callback, # callback function
            10 # queue size
        )
        self.publisher_ = self.publisher_ = self.create_publisher(String, 'topic', 10)
        self.gamepad_values = []  # Danh sách lưu giá trị gamepad
        self.prev_time = time.time()
        self.count = 0
    
    # function to send the message to the node control
    def publishMessage(self):
        msg = []
        self.publisher_.publish(msg)

    # function process input get from the teleop
    def joy_callback(self, msg):
        self.current_time = time.time()
        
        if self.current_time - self.prev_time > 5:
            self.prev_time = self.current_time
            print("Value save: ", msg.buttons, msg.axes)
            print("print count: ", self.count)
            self.count += 1

def main():
    rclpy.init()
    # use teleop to get the input of xbox gamepad
    teleop_node = subprocess.Popen(['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', "joy_config:='xbox'"])
    time.sleep(1)  # wait for teleop run

    gamepad_recorder = GamepadRecorder()

    try:
        # run rclpy.spin to process the event
        rclpy.spin(gamepad_recorder)
    except KeyboardInterrupt:
        teleop_node.terminate()
        gamepad_recorder.destroy_node()
        rclpy.shutdown()
        print("Stop completed.")
        
if __name__ == '__main__':
    main()