# * File: implement.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: September 30, 2024
# * Last Modified: October 15, 2024
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
# Class informDH: gathering the a, alpha, d, theta value between joint(i-1) and joint(i)
# Parameters:
#    the description of all parameters are listed in D-H table
class DHInform:
  def __init__(self, a, alpha, d, theta = 0):
    # assign values into a(i), alpha(i), d(i), theta(i)
    self.a          = a
    self.alpha      = alpha
    self.d          = d
    self.theta      = theta   
#-------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------  
# Class coordinatePoint: collect X, Y, Z self.endEffector of each point in space
# Parameters:
#     - X, Y, Z value is the self.endEffector of corresponding z, y, z axis 
class coordinatePoint:
  def __init__(self, X, Y, Z):
    self.X= X
    self.Y= Y
    self.Z= Z
  
  def getCoordinate(self):
    self.endEffector= np.array([self.X, self.Y, self.Z, 1]).reshape(4, -1)
    return self.endEffector
#-------------------------------------------------------------------------------------
  

# declare and define the object to convert global self.endEffector to local self.endEffector for 4 leg of robot
homoMatrixObject = homoMatrix()

# declare and define the object to convert angle of three-joint of each leg to corresponding position
positionObject = position()
  
#-------------------------------------------------------------------------------------
# Class kinematicEachLeg: the function of this class to calculate value about 
#                        the kinematicEachLeg
# Parameters:
#    - joint0, joint1, joint2 are the object of informDHEachJoint class of 
#                         corresponding joint0, joint1, joint2 of each leg 
class kinematicEachLeg:
  def __init__(self, row1DHTable, row2DHTable, row3DHTable, globalCoordinateEndEffector, legType):
    self.row1DHTable           = row1DHTable
    self.row2DHTable           = row2DHTable
    self.row3DHTable           = row3DHTable
    self.legType               = legType
    self.endEffector           = globalCoordinateEndEffector
    
  def createMatrixT(self, row_I_DHTable):
    matrixT    = np.array([[cos(row_I_DHTable.theta), -sin(row_I_DHTable.theta)*cos(row_I_DHTable.alpha), sin(row_I_DHTable.theta)*sin(row_I_DHTable.alpha), row_I_DHTable.a*cos(row_I_DHTable.theta)],
                            [sin(row_I_DHTable.theta), cos(row_I_DHTable.theta)*cos(row_I_DHTable.alpha), -cos(row_I_DHTable.theta)*sin(row_I_DHTable.alpha), row_I_DHTable.a*sin(row_I_DHTable.theta)],
                            [0, sin(row_I_DHTable.alpha), cos(row_I_DHTable.alpha), row_I_DHTable.d],
                            [0, 0, 0, 1]], dtype= np.float32)
    return matrixT

  def forwardKinematic(self, theta0, theta1, theta2):
    self.row1DHTable.theta         = theta0
    self.row2DHTable.theta         = theta1
    self.row3DHTable.theta         = theta2
    matrixT01                 = self.createMatrixT(self.row1DHTable)
    matrixT12                 = self.createMatrixT(self.row2DHTable)
    matrixT23                 = self.createMatrixT(self.row3DHTable)
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
    
    # convert global self.endEffector to local self.endEffector
    localCoordinate = homoMatrixObject.convertGlobal2LocalCoordinate(globalCoordinate, self.legType)
    
    # check the localCoordinate is valid or not
    if localCoordinate is None:
      return pairPositionJoint012
    
    # assign the local self.endEffector into X, Y, Z
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
            angleJointList = [joint0ThetaTemp, joint1ThetaTemp, joint2ThetaTemp]
            posJointList   = positionObject.convertAngle2Position(angleJointList, self.legType)
            pairPositionJoint012 = posJointList
    #-----------------------------------------------------------------------------------------
    return pairPositionJoint012
      
  def updateTrajectoryLeg(self, deviation, angleVector= 0):
    coordinatePoint1 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z + 3*deviation)
    coordinatePoint2 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z + 2*deviation)
    coordinatePoint3 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z +   deviation)
    coordinatePoint4 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z              )
    coordinatePoint5 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z -   deviation)
    coordinatePoint6 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z - 2*deviation)
    coordinatePoint7 = coordinatePoint(self.endEffector.X,      self.endEffector.Y, self.endEffector.Z - 3*deviation)
    coordinatePoint8 = coordinatePoint(self.endEffector.X+ 45,  self.endEffector.Y, self.endEffector.Z              )
    
    self.posPnt1 = self.backwardKinematic(coordinatePoint1.getCoordinate())
    self.posPnt2 = self.backwardKinematic(coordinatePoint2.getCoordinate())
    self.posPnt3 = self.backwardKinematic(coordinatePoint3.getCoordinate())
    self.posPnt4 = self.backwardKinematic(coordinatePoint4.getCoordinate())
    self.posPnt5 = self.backwardKinematic(coordinatePoint5.getCoordinate())
    self.posPnt6 = self.backwardKinematic(coordinatePoint6.getCoordinate())
    self.posPnt7 = self.backwardKinematic(coordinatePoint7.getCoordinate())
    self.posPnt8 = self.backwardKinematic(coordinatePoint8.getCoordinate())
    
    
    
class quadrupedRobot:
  def __init__(self, legRR, legRL, legFR, legFL):
    self.legRR  = legRR
    self.legRL  = legRL
    self.legFR  = legFR
    self.legFL  = legFL
    
  def updateTrajectoryAllLegs(self):
    self.legRR.updateTrajectoryLeg(deviation = 35, angleVector = 0)
    # self.legRL.updateTrajectoryLeg(deviation = 35, angleVector = 0)
    # self.legFR.updateTrajectoryLeg(deviation = 35, angleVector = 0)
    # self.legFL.updateTrajectoryLeg(deviation = 35, angleVector = 0)
    
  def out(self):
    print(self.legRR.posPnt8)
    
  def getAllPointsOfTrajectory(self):
    allPoints = list()
    allPoints.append(self.legRR.posPnt1)
    allPoints.append(self.legRR.posPnt2)
    allPoints.append(self.legRR.posPnt3)
    allPoints.append(self.legRR.posPnt4)
    allPoints.append(self.legRR.posPnt5)
    allPoints.append(self.legRR.posPnt6)
    allPoints.append(self.legRR.posPnt7)
    allPoints.append(self.legRR.posPnt8)
    return allPoints
    
    
    
  
    
def main():
  # initialize DH table of each leg of quadruped robot
  row1DHTable             = DHInform(0,                    pi/2, distance.L1.value)
  row2DHTable             = DHInform(distance.L2.value,    0,    distance.L4.value)
  row3DHTable             = DHInform(distance.L3.value,    0,    0)
  
  # declare the self.endEffector of end_effector of each leg of robot in global self.endEffector
  globalCoordinateFL = coordinatePoint(-350, 161.12, -187)    # check oke
  globalCoordinateFR = coordinatePoint(-350, -161.12, -187)   # check oke
  globalCoordinateRL = coordinatePoint(-350, 161.12, 187)     # check oke
  globalCoordinateRR = coordinatePoint(-350, -161.12, 187)    # check oke
  
  # declare the object of each leg of robot
  legFL = kinematicEachLeg(row1DHTable, row2DHTable, row3DHTable, globalCoordinateFL, leg.FL.value)
  legRR = kinematicEachLeg(row1DHTable, row2DHTable, row3DHTable, globalCoordinateRR, leg.RR.value)
  legRL = kinematicEachLeg(row1DHTable, row2DHTable, row3DHTable, globalCoordinateRL, leg.RL.value)
  legFR = kinematicEachLeg(row1DHTable, row2DHTable, row3DHTable, globalCoordinateFR, leg.FR.value)
  
  # define the quadruped robot
  dogRobotHK241 = quadrupedRobot(legRR, legRL, legFR, legFL)
  dogRobotHK241.updateTrajectoryAllLegs()
  
  trajectoryLegRR = dogRobotHK241.getAllPointsOfTrajectory()
  
  # setup ID for each ODrive on CAN network
  ODriveID = [0x01, 0x02, 0x03]
  
  # declare the CAN protocol
  CAN = CanNode()
  CAN.sendPositionContinuously(ODriveID, trajectoryLegRR)
  


if __name__ == "__main__":
  main()


# the task to complete:
#   - checking the joint0
#   - checking the position of each joint of each leg