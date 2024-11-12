from launch import LaunchDescription
from launch_ros.actions import Node
import signal
import sys
import rclpy

def signal_handler(sig, frame):
    print("Caught keyboard interrupt (SIGINT), shutting down nodes...")
    sys.exit(0)

def generate_launch_description():
    # register the signal
    signal.signal(signal.SIGINT, signal_handler)

    control = Node(
        package='controller', 
        executable='control',
        name='quadrupedRobot',
    )

    gamepad = Node(
        package='gamepad_node',
        executable='gamepad',
        name='gamepad',
    )

    can = Node(
        package='can_node',
        executable='can',
        name="canController"
    )

    return LaunchDescription([
        control,
        gamepad,
        can
    ])