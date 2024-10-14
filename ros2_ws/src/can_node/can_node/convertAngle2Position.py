# * File: convertAngle2Position.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 2, 2024
# * Last Modified: October 4, 2024
# * Description: when knowing the angle value between 2 vectors, so move the motor with position
# * Status: developing (Done, brainStorm, developing)
# kẹt ở hàm convertAngle2Position()

#import framework
from math import pi
from enum import Enum

# define the step per degree of joint0, joint1, joint2
class stepPerDegree(Enum):
  joint0     =          9/(2*pi)
  joint1     =          9/(2*pi)
  joint2     =          2.5/(2*pi)
  
# define the type of leg
class leg(Enum):
  FR                  = 1
  FL                  = 2
  RR                  = 3
  RL                  = 4

# declare the enum for each leg of quadruped robot
class limitRR(Enum):
  joint0UpperLimit      =           1.7
  joint0LowerLimit      =           -2.9
  joint0Middle          =           -0.6

  joint1UpperLimit      =           1.9
  joint1LowerLimit      =           -2.7
  joint1Middle          =           -0.4

  joint2UpperLimit      =           1
  joint2LowerLimit      =           -0.25
  joint2Middle          =           0.375
  
class limitRL(Enum):
  joint0Middle          =           -0.6
  joint1Middle          =           -0.4
  joint2Middle          =           0.375
  
class limitFR(Enum):
  joint0Middle          =           -0.6
  joint1Middle          =           -0.4
  joint2Middle          =            0.375

class limitFL(Enum):
  joint0Middle          =           -0.6
  joint1Middle          =           -0.4
  joint2Middle          =            0.375

class position:
  def __init__(self):
    print("Empty")
  
  def convertAngle2PositionJoint0(angle, legType):
    joint0PositionCurrent = joint0Middl
    if angle == 0:
      joint0PositionCurrent = joint0Middle
    if angle > 0:
      joint0PositionCurrent = joint0Middle + abs(angle)*stepPerDegree.joint0.value
    if angle < 0:
      joint0PositionCurrent = joint0Middle - abs(angle)*stepPerDegree.joint0.value
    return joint0PositionCurrent

  def convertAngle2PositionJoint1(angle, legType):
    joint1PositionCurrent   = joint1Middle
    if angle > pi/2:
      joint1PositionCurrent = joint1Middle - abs(pi - angle)*stepPerDegree.joint1.value
    if angle < -pi/2:
      joint1PositionCurrent = joint1Middle + abs(pi + angle)*stepPerDegree.joint1.value
    
    return joint1PositionCurrent
    
  def convertAngle2PositionJoint2(angle, legType):
    joint2PositionCurrent = joint2Middle
    if angle == 0:
      joint2PositionCurrent = joint2Middle
    if angle < 0:
      joint2PositionCurrent = joint2Middle - abs(angle)*stepPerDegree.joint2.value
    if angle > 0:
      joint2PositionCurrent = joint2Middle + abs(angle)*stepPerDegree.joint2.value
    return joint2PositionCurrent

  def convertAngle2Position(self, angleJoint0, angleJoint1, angleJoint2, legType):
    positionJoint0 = self.convertAngle2PositionJoint0(angleJoint0, legType)
    positionJoint1 = self.convertAngle2PositionJoint1(angleJoint1, legType)
    positionJoint2 = self.convertAngle2PositionJoint2(angleJoint2, legType)