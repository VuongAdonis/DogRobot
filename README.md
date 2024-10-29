# Capstone Project: DOGROBOT


# ROS2_CAN_NODE:

- The source of controlling CAN communication
  issue: noise when control 2 ODrive

- To run can_node:
  $ ros2 run can_node can

Note: The publisher and subscriber file in the can_node is just use to test for the ROS2, not relative to the robot.

## ROS2_GAMEPAD_NODE:

The source to read the input of gamepad 360

gamepad.py: file to read the input of gamepad 360

Button Y:

Button A:

Button X:

Button B:

joy1: control move of the robot

If you want to use the other gamepad, change the joy_config to this name of gamepad you want to use.

teleop_node = subprocess.Popen(['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', "joy_config:='xbox'"])

### To read this input:

#### In the terminal run:

$ ros2 run gamepad_node gamepad

## ROS2_CONTROLLER_NODE:

- Description:
  - In this folder, which includes some files such as
    - Convert the angle to position of each leg of quadruped robot.
    - Convert the coordinate of each leg in global into local coordinate
    - Forward and inverse kinematic to calculate the angle of each motor of quadruped robot
    - The main file is quadrupedRobot.py to control all operations of quadruped robot
- Progress to build and run:
  - $ ros2 run controller control

# Phase test for the Robot:

phase test is placed in path "DogRobot\ros2_ws\src\controller\controller.quadrupedRobot.py"

# Communication:

## 1. Between control and gamepad:

- We using the service of the ROS2
- quadrupedRobot(client) send request to the gamepad (server) to get the response contain value of joy1.

## 2. Between control and can_node

- We using publish and subscribe to a topic of ROS2
- The quadrupedRobot will publish the message type PublishMessage in the custom_interfaces/msg. The can_node will receive and then send the position to the ODrive using CAN bus
