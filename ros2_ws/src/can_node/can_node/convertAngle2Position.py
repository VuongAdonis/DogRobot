# * File: convertAngle2Position.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 2, 2024
# * Last Modified: October 14, 2024
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

# declare the enum for each leg of quadruped robotz
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
  
  def convertAngle2PositionJoint0(self, angle, legType):
    if legType == leg.RR.value:
      joint0PositionCurrent = limitRR.joint0Middle.value
      if angle == 0:
        joint0PositionCurrent = limitRR.joint0Middle.value
      if angle > 0:
        joint0PositionCurrent = limitRR.joint0Middle.value + abs(angle)*stepPerDegree.joint0.value
      if angle < 0:
        joint0PositionCurrent = limitRR.joint0Middle.value - abs(angle)*stepPerDegree.joint0.value
      return joint0PositionCurrent

  def convertAngle2PositionJoint1(self, angle, legType):
    if legType == leg.RR.value:
      joint1PositionCurrent   = limitRR.joint1Middle.value
      if angle > pi/2:
        joint1PositionCurrent = limitRR.joint1Middle.value - abs(pi - angle)*stepPerDegree.joint1.value
      if angle < -pi/2:
        joint1PositionCurrent = limitRR.joint1Middle.value + abs(pi + angle)*stepPerDegree.joint1.value
    
      return joint1PositionCurrent
    
  def convertAngle2PositionJoint2(self, angle, legType):
    if legType == leg.RR.value:
      joint2PositionCurrent = limitRR.joint2Middle.value
      if angle == 0:
        joint2PositionCurrent = limitRR.joint2Middle.value
      if angle < 0:
        joint2PositionCurrent = limitRR.joint2Middle.value - abs(angle)*stepPerDegree.joint2.value
      if angle > 0:
        joint2PositionCurrent = limitRR.joint2Middle.value + abs(angle)*stepPerDegree.joint2.value
      return joint2PositionCurrent

  def convertAngle2Position(self, angleLeg, legType):
    positionJoint0 = self.convertAngle2PositionJoint0(angleLeg[0], legType)
    positionJoint1 = self.convertAngle2PositionJoint1(angleLeg[1], legType)
    positionJoint2 = self.convertAngle2PositionJoint2(angleLeg[2], legType)
    return [positionJoint0, positionJoint1, positionJoint2]