 # DOGROBOT

## can_node:
The source for control CAN communication
issue: noise when control 2 ODrive

## gamepad_node:
The source to read the input of gamepad 360

gamepad.py: file to read the input of gamepad 360

If you want to use the other gamepad, change the joy_config to this name of gamepad you want to use.

teleop_node = subprocess.Popen(['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', "joy_config:='xbox'"])

### To read this input:
#### In the terminal run:
$ ros2 run gamepad_node gamepad

## Controller:
To control moving of the dog's robot

# Phase test for the Robot:
phase test is placed in path "DogRobot\ros2_ws\src\controller\controller.quadrupedRobot.py"
