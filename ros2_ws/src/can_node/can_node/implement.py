# * File: implement.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: September 30, 2024
# * Last Modified: October 14, 2024
# * Description: this file to calculate forward and backward kinematic of ROBOT
# * Status: developing (Done, brainStorm, developing)

# FORMAT: D-H table to represent interaction between of joint(i-1) and joint(i)
# Parameters:
#   1. a(i):
#       - Unit: mm
#       - Description: distance between vector Z(i) and Z(i-1)
#   2. alpha(i):
#       - Unit: radians
#       - Description: angle between vector Z(i) and Z(i-1)
#   3. d(i):
#       - Unit: mm
#       - Description: distance between vector X(i) and X(i-1)
#   4. theta(i):
#       - Unit: radians
#       - Description: angle between vector X(i) and X(i-1)

#--------------------------------------------------------------------
# orderJoint    | a(i)    | alpha(i)  | d(i)  |     theta(i)        |
# ------------------------------------------------------------------
# i= 1 (joint0) |   0     |   pi/2    |  L1   | 0 + angle_joint0(a1)|
# -------------------------------------------------------------------
# i= 2 (joint1) |   L2    |     0     |  L4   |   angle_joint1(a2)  |
# -------------------------------------------------------------------
# i= 3 (joint2) |   L3    |     0     |   0   |   angle_joint(a3)   |
#--------------------------------------------------------------------

# import framework
import numpy as np
from math import cos, sin, radians, pi, atan2, sqrt, atan, acos, asin
from convertAngle2Position import position
from convertCoordinate import homoMatrix
from enum import Enum
from can_controller import CanNode

#-------------------------------------------------------------------------------------
# Class distance: define the distance between several vectors
# Parameters:
#     - L1: the length between X0 and X1 vector
#     - L2: the length between Z1 and Z2 vector
#     - L3: the length between z2 and z3 vector
#     - L4: the length between x1 and x2 vector
class distance(Enum):
  L1                  = 134.1   
  L2                  = 200    
  L3                  = 200    
  L4                  = 86.12 
#-------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------    
# Class leg: define 4 leg of quadruped robot
# Parameters:
#     - FR: front right leg
#     - FL: front left leg
#     - RR: rear right leg
#     - RL: rear left leg
class leg(Enum):
  FR                  = 1
  FL                  = 2
  RR                  = 3
  RL                  = 4
#-------------------------------------------------------------------------------------

#-------------------------------------------------------------------------------------
# Class OdriveID:

class OdriveID():
  pass
#-------------------------------------------------------------------------------------

#-------------------------------------------------------------------------------------
# Class informDH: gathering the a, alpha, d, theta value
# Parameters:
#    the description of all parameters are listed in D-H table
class informDHEachJoint:
  def __init__(self, a, alpha, d, theta = 0):
    # assign values into a(i), alpha(i), d(i), theta(i)
    self.a          = a
    self.alpha      = alpha
    self.d          = d
    self.theta      = theta   
#-------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------  
# Class coordinatePoint: collect X, Y, Z coordinate of each point in space
# Parameters:
#     - X, Y, Z value is the coordinate of corresponding z, y, z axis 
class coordinatePoint:
  def __init__(self, X, Y, Z):
    self.X= X
    self.Y= Y
    self.Z= Z
  
  def getCoordinate(self):
    coordinate= np.array([self.X, self.Y, self.Z, 1]).reshape(4, -1)
    return coordinate
#-------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------  
# Class trajectory: define several points to particular leg moves with desired trajectory
# Parameters: all parameters have the same unit (mm)
#    - XOriginal: the X value on x axis of global coordinate
#    - YOriginal: the Y value on y axis of global coordinate
#    - ZOriginal: the Z value on z axis of global coordinate
#    - deviation: the value to represent the distance between 2 points in stance phase (<= 50mm)
class trajectoryLeg:
  def __init__(self, XOriginal, YOriginal, ZOriginal, deviation):
    # deviation is about 35mm
    self.coordinatePoint1 = coordinatePoint(XOriginal, YOriginal, ZOriginal + 3*deviation)
    self.coordinatePoint2 = coordinatePoint(XOriginal, YOriginal, ZOriginal + 2*deviation)
    self.coordinatePoint3 = coordinatePoint(XOriginal, YOriginal, ZOriginal + deviation)
    self.coordinatePoint4 = coordinatePoint(XOriginal, YOriginal, ZOriginal)
    self.coordinatePoint5 = coordinatePoint(XOriginal, YOriginal, ZOriginal - deviation)
    self.coordinatePoint6 = coordinatePoint(XOriginal, YOriginal, ZOriginal - 2*deviation)
    self.coordinatePoint7 = coordinatePoint(XOriginal, YOriginal, ZOriginal - 3*deviation)
    self.coordinatePoint8 = coordinatePoint(XOriginal+ 45, YOriginal, ZOriginal)
    
    
  # def updateGlobalCoordinate(self):
#-------------------------------------------------------------------------------------

  

# declare and define the object to convert global coordinate to local coordinate for 4 leg of robot
homoMatrixObject = homoMatrix()

# declare and define the object to convert angle of three-joint of each leg to corresponding position
positionObject = position()
  
#-------------------------------------------------------------------------------------
# Class kinematicRobot: the function of this class to calculate value about 
#                        the kinematicRobot
# Parameters:
#    - joint0, joint1, joint2 are the object of informDHEachJoint class of 
#                         corresponding joint0, joint1, joint2 of each leg 
class kinematicRobot:
  
  def __init__(self, joint0, joint1, joint2, legType):
    self.joint0           = joint0
    self.joint1           = joint1
    self.joint2           = joint2
    self.legType          = legType
    
  def createMatrixT(self, joint):
    matrixT    = np.array([[cos(joint.theta), -sin(joint.theta)*cos(joint.alpha), sin(joint.theta)*sin(joint.alpha), joint.a*cos(joint.theta)],
                            [sin(joint.theta), cos(joint.theta)*cos(joint.alpha), -cos(joint.theta)*sin(joint.alpha), joint.a*sin(joint.theta)],
                            [0, sin(joint.alpha), cos(joint.alpha), joint.d],
                            [0, 0, 0, 1]], dtype= np.float32)
    return matrixT

  def forwardKinematic(self, theta0, theta1, theta2):
    self.joint0.theta         = theta0
    self.joint1.theta         = theta1
    self.joint2.theta         = theta2
    matrixT01                 = self.createMatrixT(self.joint0)
    matrixT12                 = self.createMatrixT(self.joint1)
    matrixT23                 = self.createMatrixT(self.joint2)
    matrixT03                 = (matrixT01.dot(matrixT12)).dot(matrixT23)
    XEnd_effector             = matrixT03[0, 3]
    YEnd_effector             = matrixT03[1, 3]
    ZEnd_effector             = matrixT03[2, 3]
    return XEnd_effector, YEnd_effector, ZEnd_effector
  
  def calculateJoint0Angle(self, joint1ThetaTemp, joint2ThetaTemp, X):
    joint0ThetaTemp = list()
    a = distance.L3.value*cos(joint1ThetaTemp + joint2ThetaTemp) + distance.L2.value*cos(joint1ThetaTemp)
    b = distance.L4.value
    d= X
    
    alpha = atan2(a/sqrt(a**2 + b**2), b/sqrt(a**2 + b**2))
    
    joint0ThetaTemp0 = atan2(d/sqrt(a**2 + b**2), sqrt(1- d**2/(a**2 + b**2))) - alpha
    joint0ThetaTemp1 = atan2(d/sqrt(a**2 + b**2), -sqrt(1- d**2/(a**2 + b**2))) - alpha
      
    if joint0ThetaTemp0== joint0ThetaTemp1:
      if abs(joint0ThetaTemp0) < pi/2:  # modify limit of angle joint0
        joint0ThetaTemp.append(joint0ThetaTemp0)
    else:
      if abs(joint0ThetaTemp0) < pi/2: # modify limit of angle joint0
        joint0ThetaTemp.append(joint0ThetaTemp0)
      if abs(joint0ThetaTemp1) < pi/2:  # modify limit of angle joint0
        joint0ThetaTemp.append(joint0ThetaTemp1)
    return joint0ThetaTemp

  def calculateJoint1Angle(self, joint2ThetaTemp, Z):
    joint1ThetaTemp = list()
    a = distance.L3.value*sin(joint2ThetaTemp)
    b= distance.L3.value*cos(joint2ThetaTemp) + distance.L2.value
    d = Z - distance.L1.value
    alpha = atan2(a/sqrt(a**2 + b**2), b/sqrt(a**2 + b**2))
    
    joint1ThetaTemp0 = atan2(d/sqrt(a**2 + b**2), sqrt(1- d**2/(a**2 + b**2))) - alpha   
    if abs(joint1ThetaTemp0) > pi:
      if joint1ThetaTemp0 > 0:
        joint1ThetaTemp0 = -(2*pi - abs(joint1ThetaTemp0))
      else:
        joint1ThetaTemp0= 2*pi - abs(joint1ThetaTemp0)
           
    joint1ThetaTemp1 = atan2(d/sqrt(a**2+ b**2), -sqrt(1- d**2/(a**2 + b**2))) - alpha
    if abs(joint1ThetaTemp1) > pi:
      if joint1ThetaTemp1 > 0:
        joint1ThetaTemp1 = -(2*pi - abs(joint1ThetaTemp1))
      else:
        joint1ThetaTemp1= 2*pi - abs(joint1ThetaTemp1)

    if (joint1ThetaTemp0 == joint1ThetaTemp1):
      if (self.legType== leg.RR.value) or (self.legType== leg.FL.value):
        if abs(joint1ThetaTemp0) > pi/2:    # modify limit of angle joint1
          joint1ThetaTemp.append(joint1ThetaTemp0)
      if (self.legType== leg.RL.value) or (self.legType== leg.FR.value):
        if abs(joint1ThetaTemp0) < pi/2:   # modify limit of angle joint1
          joint1ThetaTemp.append(joint1ThetaTemp0)
    else:
      if (self.legType== leg.RR.value) or (self.legType== leg.FL.value):
        if abs(joint1ThetaTemp0) > pi/2:    # modify limit of angle joint1
          joint1ThetaTemp.append(joint1ThetaTemp0)
        if abs(joint1ThetaTemp1) > pi/2:    # modify limit of angle joint1
          joint1ThetaTemp.append(joint1ThetaTemp1)
      if (self.legType == leg.RL.value) or (self.legType== leg.FR.value):
        if abs(joint1ThetaTemp0) < pi/2:    # modify limit of angle joint1
          joint1ThetaTemp.append(joint1ThetaTemp0)
        if abs(joint1ThetaTemp1) < pi/2:    # modify limit of angle joint1
          joint1ThetaTemp.append(joint1ThetaTemp1)
          
    return joint1ThetaTemp
  
  def calculateJoint2Angle(self, X, Y, Z):
    joint2ThetaTemp= list()
    cosJoint2 = (X**2 + Y**2 + (Z- distance.L1.value)**2 - (distance.L2.value)**2 - (distance.L3.value)**2 - (distance.L4.value)**2)/(2*(distance.L2.value)*(distance.L3.value))
    if (cosJoint2 > 1) or (cosJoint2 < -1):
      return joint2ThetaTemp
    sinJoint2 = sqrt(1- cosJoint2**2)
    # the value of atan2 with (sin and cos is equal or greater than 0) is from 0 to pi/2
    if atan2(sinJoint2, cosJoint2) <= pi/2:
      if (self.legType == leg.RR.value) or (self.legType == leg.FR.value):
        joint2ThetaTemp = [atan2(sinJoint2, cosJoint2)]
      if (self.legType == leg.FL.value) or (self.legType == leg.RL.value):
        joint2ThetaTemp = [-atan2(sinJoint2, cosJoint2)]
      
    return joint2ThetaTemp
  
  def backwardKinematic(self, globalCoordinate):
    pairPositionJoint012 = list()
    
    # convert global coordinate to local coordinate
    localCoordinate = homoMatrixObject.convertGlobal2LocalCoordinate(globalCoordinate, self.legType)
    print("Local: ", localCoordinate.reshape(-1, 4))
    
    # check the localCoordinate is valid or not
    if localCoordinate is None:
      return pairPositionJoint012
    
    # assign the local coordinate into X, Y, Z
    X, Y, Z= localCoordinate[0][0], localCoordinate[1][0], localCoordinate[2][0]
    
    #----------------------Determine the value of theta2 of JOINT2---------------------------
    joint2ThetaTempList= self.calculateJoint2Angle(X, Y, Z)
    #----------------------------------------------------------------------------------------
    
    #----------------------Determine the value of theta1 of JOINT1---------------------------
    for joint2ThetaTemp in joint2ThetaTempList:
      joint1ThetaTempList = self.calculateJoint1Angle(joint2ThetaTemp, Z)
      for joint1ThetaTemp in joint1ThetaTempList:
        #---------------Determine the value of theta0 of JOINT0------------------------------
        joint0ThetaTempList = self.calculateJoint0Angle(joint1ThetaTemp, joint2ThetaTemp, X)
        #------------------------------------------------------------------------------------
        for joint0ThetaTemp in joint0ThetaTempList:
          XPredict, YPredict, ZPredict= self.forwardKinematic(joint0ThetaTemp, joint1ThetaTemp, joint2ThetaTemp)
          if (XPredict- X)**2 + (YPredict- Y)**2 + (ZPredict -Z)**2 < 0.001:
            # joint0Position= convertAngle2PositionJoint0(joint0ThetaTemp)
            # joint1Position= convertAngle2PositionJoint1(joint1ThetaTemp)
            # joint2Position= convertAngle2PositionJoint2(joint2ThetaTemp)
            # pairPositionJoint012.append([joint0Position, joint1Position, joint2Position])
            pairPositionJoint012.append([joint0ThetaTemp, joint1ThetaTemp, joint2ThetaTemp])
            # joint0Pos, joint1Pos, joint2Pos= self.positionObject.convertAngle2Position(joint0ThetaTemp, joint1ThetaTemp, joint2ThetaTemp, self.legType)
            
    #-----------------------------------------------------------------------------------------
    return pairPositionJoint012
    
    #   print(actualPairJoint012)
    #   joint0PositionCurrent = convertAngle2PositionJoint0(actualPairJoint012[0][0])
    #   joint1PositionCurrent = convertAngle2PositionJoint1(actualPairJoint012[0][1])
    #   joint2PositionCurrent = convertAngle2PositionJoint2(actualPairJoint012[0][2])
    #   print("positionJoint0: ", joint0PositionCurrent)
    #   print("positionJoint1: ", joint1PositionCurrent)
    #   print("positionJoint2: ", joint2PositionCurrent)

def main():
  # initialize three joints Object, each joint has three data fields a, alpha, d
  joint0Object        = informDHEachJoint(0,                    pi/2, distance.L1.value)
  joint1Object        = informDHEachJoint(distance.L2.value,    0,    distance.L4.value)
  joint2Object        = informDHEachJoint(distance.L3.value,    0,    0)
  
  
  # the value to move up and down from -(L2+ L3) to -L2
  # lower = -(L2 + L3)
  # X = [lower, lower+ 20, lower+ 40, lower+ 80, lower+ 100, lower+ 120, lower+ 140, lower+ 160, lower+ 180, lower+ 200]
  # Y= -L4
  # Z= L1
  
  # declare the coordinate of each leg of robot on original coordinate
  globalCoordinateFL = coordinatePoint(-350, 161.12, -187)    # check oke
  globalCoordinateFR = coordinatePoint(-350, -161.12, -187)   # check oke
  globalCoordinateRL = coordinatePoint(-350, 161.12, 187)     # check oke
  globalCoordinateRR = coordinatePoint(-350, -161.12, 187)    # check oke
  
  # declare the object of each leg of robot
  FLObject = kinematicRobot(joint0Object, joint1Object, joint2Object, leg.FL.value)
  RRObject = kinematicRobot(joint0Object, joint1Object, joint2Object, leg.RR.value)
  RLObject = kinematicRobot(joint0Object, joint1Object, joint2Object, leg.RL.value)
  FRObject = kinematicRobot(joint0Object, joint1Object, joint2Object, leg.FR.value)

  # declare the object for CAN communication
  canObject = CanNode()
  canObject.sendClosedLoop(1)
  
  # print angle of each leg, which includes angle of joint0, joint1 and joint2 of quadruped robot
  # print("AngleFL: ", FLObject.backwardKinematic(globalCoordinateFL.getCoordinate()))
  # print("AngleRR: ", RRObject.backwardKinematic(globalCoordinateRR.getCoordinate()))
  # print("AngleRL: ", FRObject.backwardKinematic(globalCoordinateRL.getCoordinate()))
  # print("AngleFR: ", FRObject.backwardKinematic(globalCoordinateFR.getCoordinate()))
  trajectoryLegFL = trajectoryLeg(globalCoordinateFL.X, globalCoordinateFL.Y, globalCoordinateFL.Z, 35)
  
  point1 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint1.getCoordinate())
  point2 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint8.getCoordinate())
  point3 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint7.getCoordinate())
  point4 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint6.getCoordinate())
  point5 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint5.getCoordinate())
  point6 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint4.getCoordinate())
  point6 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint3.getCoordinate())
  point7 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint2.getCoordinate())
  point8 = FLObject.backwardKinematic(trajectoryLegFL.coordinatePoint1.getCoordinate())


if __name__ == "__main__":
  main()


# the task to complete:
#   - checking the joint0
#   - checking the position of each joint of each leg