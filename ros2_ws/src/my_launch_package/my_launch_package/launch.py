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

    talker = Node(
        package='can_node', 
        executable='talker',
        name='talker_node',
    )

    listener = Node(
        package='can_node',
        executable='listener',
        name='listener_node',
    )

    return LaunchDescription([
        talker,
        listener,
    ])