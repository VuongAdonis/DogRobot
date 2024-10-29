# * File: gamepad.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 17, 2024
# * Last Modified: October 17, 2024
# * Description: the program to read input of gamepad
# * Status: developing (Done, brainStorm, developing):

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
import subprocess
import time
from custom_interfaces.srv import GamepadSrv

class GamepadRecorder(Node):
    def __init__(self):
        super().__init__('gamepad_recorder')
        self.subscription = self.create_subscription(
            Joy, # message type
            'joy', # topic
            self.joy_callback, # callback function
            10 # queue size
        )
        self.gamepad_values = []  # list save the gamepad's value
        self.prev_time = time.time()
        self.count = 0
        self.buttonStandUp = 0
        self.buttonStandDown = 0
        self.buttonStandNormal = 0

        self.service = self.create_service(
            GamepadSrv,
            "gamepad",
            self.gamepad_callback
        )

    # service function of gamepad
    def gamepad_callback(self, request, response):
        response.position = [self.x, self.y]
        response.button_stand_up = self.buttonStandUp
        response.button_stand_down = self.buttonStandDown
        response.button_stand_normal = self.buttonStandNormal

        # self.get_logger().info(f"Incoming request\na: {request.a} b:{request.b}")
        self.get_logger().info(f"Incoming request\n")
        return response

    # function process input get from the teleop
    def joy_callback(self, msg):
        self.current_time = time.time()
        self.x = msg.axes[0]
        self.y = msg.axes[1]
        self.buttonStandUp = msg.buttons[3]
        self.buttonStandDown = msg.buttons[0]
        self.buttonStandNormal = msg.buttons[7]

        print("UP: ", self.buttonStandUp)
        print("DOWN: ", self.buttonStandDown)
        print("NORMAL: ", self.buttonStandNormal)
        time.sleep(2)


def main():
    rclpy.init()
    # use teleop to get the input of xbox gamepad
    teleop_node = subprocess.Popen(['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', "joy_config:='xbox'"])
    time.sleep(1)  # wait for teleop run

    gamepad_recorder = GamepadRecorder()

    rclpy.spin(gamepad_recorder)
    teleop_node.terminate()
    gamepad_recorder.destroy_node()
    rclpy.shutdown()
        
if __name__ == '__main__':
    main()