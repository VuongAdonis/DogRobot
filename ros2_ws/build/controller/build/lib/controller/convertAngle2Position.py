# * File: convertAngle2Position.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 2, 2024
# * Last Modified: October 30, 2024
# * Description: when knowing the angle value between 2 vectors, so move the motor with position
# * Status: developing (Done, brainStorm, developing):
#         - check and update all originalPos of RR, RL, FL, FR


#import framework
from math import pi
from enum import Enum
from controller.convertGlobal2LocalCoordinate import leg


#---------------------------------------------------------------------------------------------------------------------#
# Class's name: 
#   - stepPerDegree
# Description:
#   - Define some rates of gear
class stepPerDegree(Enum):
  joint0     =          9/(2*pi)
  joint1     =          9/(2*pi)
  joint2     =          5/(2*pi)
#---------------------------------------------------------------------------------------------------------------------#
  

# declare the enum for each leg of quadruped robotz
class originalPosRR(Enum):
  joint0Middle          =           0.4
  joint1Middle          =           0.52
  joint2Middle         =            -0.25
  
class originalPosRL(Enum):
  joint0Middle          =           -0.08
  joint1Middle          =           -0.26
  joint2Middle          =            -0.09
  
class originalPosFR(Enum):
  joint0Middle          =            0.43
  joint1Middle          =           -0.95
  joint2Middle          =            -0.28

class originalPosFL(Enum):
  joint0Middle          =           -0.55
  joint1Middle          =           0.08
  joint2Middle          =           -0.06

#---------------------------------------------------------------------------------------------------------------------#
# Class's name:
#   - position
# Description:
#   - Declare and define some functions to convert the exist angle to the specific position for each motor
class position:
  
  def convertAngle2PositionJoint0(self, angle, legType):
    if legType == leg.RR.value:
      joint0PositionCurrent = originalPosRR.joint0Middle.value
      if angle > 0.0001:
        joint0PositionCurrent = originalPosRR.joint0Middle.value + abs(angle)*stepPerDegree.joint0.value
      if angle < -0.0001:
        joint0PositionCurrent = originalPosRR.joint0Middle.value - abs(angle)*stepPerDegree.joint0.value

    if legType == leg.FR.value:
      joint0PositionCurrent = originalPosFR.joint0Middle.value
      if angle > 0.0001:
        joint0PositionCurrent = originalPosFR.joint0Middle.value + abs(angle)*stepPerDegree.joint0.value
      if angle < -0.0001:
        joint0PositionCurrent = originalPosFR.joint0Middle.value - abs(angle)*stepPerDegree.joint0.value

    if legType == leg.RL.value:
      joint0PositionCurrent = originalPosRL.joint0Middle.value
      if angle > 0.0001:
        joint0PositionCurrent = originalPosRL.joint0Middle.value + abs(angle)*stepPerDegree.joint0.value
      if angle < -0.0001:
        joint0PositionCurrent = originalPosRL.joint0Middle.value - abs(angle)*stepPerDegree.joint0.value
  
    if legType == leg.FL.value:
      joint0PositionCurrent = originalPosFL.joint0Middle.value
      if angle > 0.0001:
        joint0PositionCurrent = originalPosFL.joint0Middle.value + abs(angle)*stepPerDegree.joint0.value
      if angle < -0.0001:
        joint0PositionCurrent = originalPosFL.joint0Middle.value - abs(angle)*stepPerDegree.joint0.value
    return joint0PositionCurrent

  def convertAngle2PositionJoint1(self, angle, legType):
    if legType == leg.RR.value:
      joint1PositionCurrent   = originalPosRR.joint1Middle.value
      if angle > 0.0001:
        joint1PositionCurrent = originalPosRR.joint1Middle.value - abs(pi- angle)*stepPerDegree.joint1.value
      else:
        if angle < -0.0001:
          joint1PositionCurrent = originalPosRR.joint1Middle.value + abs(pi+ angle)*stepPerDegree.joint1.value
          
    if legType == leg.RL.value:
      joint1PositionCurrent   = originalPosRL.joint1Middle.value
      if angle > 0.0001:
        joint1PositionCurrent = originalPosRL.joint1Middle.value + abs(angle)*stepPerDegree.joint1.value
      else:
        if angle < -0.0001:
          joint1PositionCurrent = originalPosRL.joint1Middle.value - abs(angle)*stepPerDegree.joint1.value
    
    if legType == leg.FR.value:
      joint1PositionCurrent   = originalPosFR.joint1Middle.value
      if angle > 0.0001:
        joint1PositionCurrent = originalPosFR.joint1Middle.value + abs(angle)*stepPerDegree.joint1.value
      else:
        if angle < -0.0001:
           joint1PositionCurrent = originalPosFR.joint1Middle.value - abs(angle)*stepPerDegree.joint1.value
      
    if legType == leg.FL.value:
      joint1PositionCurrent   = originalPosFL.joint1Middle.value
      if angle > 0.0001:
        joint1PositionCurrent = originalPosFL.joint1Middle.value - abs(pi- angle)*stepPerDegree.joint1.value
      else:
        if angle < -0.0001:
          joint1PositionCurrent = originalPosFL.joint1Middle.value + abs(pi+ angle)*stepPerDegree.joint1.value
    return joint1PositionCurrent
  
  def convertAngle2PositionJoint2(self, angle, legType):
    if legType == leg.RR.value: # angle > 0
      joint2PositionCurrent = originalPosRR.joint2Middle.value
      if angle > 0.0001:
        joint2PositionCurrent = originalPosRR.joint2Middle.value + abs(angle)*stepPerDegree.joint2.value
    if legType == leg.FR.value: # angle > 0
      joint2PositionCurrent = originalPosFR.joint2Middle.value
      if angle > 0.0001:
        joint2PositionCurrent = originalPosFR.joint2Middle.value + abs(angle)*stepPerDegree.joint2.value
    if legType == leg.RL.value: # angle < 0
      joint2PositionCurrent = originalPosRL.joint2Middle.value
      if angle < -0.0001:
        joint2PositionCurrent = originalPosRL.joint2Middle.value - abs(angle)*stepPerDegree.joint2.value
    if legType == leg.FL.value: # angle < 0
      joint2PositionCurrent = originalPosFL.joint2Middle.value
      if angle < -0.0001:
        joint2PositionCurrent = originalPosFL.joint2Middle.value - abs(angle)*stepPerDegree.joint2.value
    return joint2PositionCurrent

  def convertAngle2Position(self, angleLeg, legType):
    positionJoint0 = self.convertAngle2PositionJoint0(angleLeg[0], legType)
    positionJoint1 = self.convertAngle2PositionJoint1(angleLeg[1], legType)
    positionJoint2 = self.convertAngle2PositionJoint2(angleLeg[2], legType)
    return [positionJoint0, positionJoint1, positionJoint2]
#---------------------------------------------------------------------------------------------------------------------#