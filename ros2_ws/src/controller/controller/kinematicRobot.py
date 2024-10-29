# * File: implement.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: September 30, 2024
# * Last Modified: October 22, 2024
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
from math import cos, sin,pi, atan2, sqrt
from enum import Enum
from controller.convertGlobal2LocalCoordinate import leg
from controller.convertAngle2Position import position
from controller.convertGlobal2LocalCoordinate import homoMatrix


#---------------------------------------------------------------------------------------------------------------------#
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
#---------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------#
# Class informDH: 
# Description: 
#   - Gathering the a, alpha, d, theta value between joint(i-1) and joint(i)
# Parameters:
#   - Responsible of all parameters are listed in D-H table
class DHInform:
  def __init__(self, a, alpha, d, theta = 0):
    # assign values into a(i), alpha(i), d(i), theta(i)
    self.a          = a
    self.alpha      = alpha
    self.d          = d
    self.theta      = theta   
#---------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------#  
# Class's name:
#     - coordinatePoint: 
# Description:
#     - Collect X, Y, Z self.endEffector of each point in space
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
#---------------------------------------------------------------------------------------------------------------------#
  
  
#---------------------------------------------------------------------------------------------------------------------#
# Class's name:
#    - kinematicEachLeg
# Description:
#    - The function of this class to calculate value about the kinematicEachLeg
# Parameters:
#    - legType: is the type of leg in quadruped robot, such as: RR, RL, FR, FL
#    - endEffector: is the global coordinate of end_effector of specific leg
#    - row1DHTable, row2DHTable, row3DHTable: are the components of table information
class kinematicEachLeg:
  
  def __init__(self, globalCoordinateEndEffector, legType):
    self.row1DHTable             = DHInform(0,                    pi/2, distance.L1.value)
    self.row2DHTable             = DHInform(distance.L2.value,    0,    distance.L4.value)
    self.row3DHTable             = DHInform(distance.L3.value,    0,    0)
    self.legType                 = legType
    self.endEffector             = globalCoordinateEndEffector
    self.homoMatrixObject        = homoMatrix()
    self.cvt2PosObject           = position()
    
  def updatePositionEndEffector(self, newPositionEndEffector):
    self.endEffector.X = newPositionEndEffector[0][0]
    self.endEffector.Y = newPositionEndEffector[0][1]
    self.endEffector.Z = newPositionEndEffector[0][2]
    
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
      if abs(joint0ThetaTemp0) < pi/3:  # modify limit of angle joint0
        joint0ThetaTemp.append(joint0ThetaTemp0)
    else:
      if abs(joint0ThetaTemp0) < pi/3: # modify limit of angle joint0
        joint0ThetaTemp.append(joint0ThetaTemp0)
      if abs(joint0ThetaTemp1) < pi/3:  # modify limit of angle joint0
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
        if abs(joint1ThetaTemp1) > 2*pi/4:    # modify limit of angle joint1
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
    # if atan2(sinJoint2, cosJoint2) <= pi/2:  # may be modified
    if (self.legType == leg.RR.value) or (self.legType == leg.FR.value):
      joint2ThetaTemp = [atan2(sinJoint2, cosJoint2)]
    if (self.legType == leg.FL.value) or (self.legType == leg.RL.value):
      joint2ThetaTemp = [-atan2(sinJoint2, cosJoint2)]
      
    return joint2ThetaTemp
  
  def backwardKinematic(self, globalCoordinate):
    pairPositionJoint012 = list()
    
    # convert global self.endEffector to local self.endEffector
    localCoordinate = self.homoMatrixObject.convertGlobal2LocalCoordinate(globalCoordinate, self.legType)
    
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
            posJointList   = self.cvt2PosObject.convertAngle2Position(angleJointList, self.legType)
            pairPositionJoint012 = posJointList
    #-----------------------------------------------------------------------------------------
    return pairPositionJoint012
      
  # value of some variables can be modified: angleVector, high, deviation, X coordinate
  def updatePosTrajectoryLeg(self, deviation, angleVector):
    high = 40
    sign123Y = 0
    sign123Z = 0
    sign567Y = 0
    sign567Z = 0
    stepY = 0
    stepZ = 0
    if abs(angleVector) <= pi/2:
      if angleVector >= 0:  # y < 0 and z < 0
        # point 1, 2, 3 has y increase, z increase
        sign123Y = 1
        sign123Z = 1
        # point 5, 6, 7 has y decrease, z decrease
        sign567Y = -1
        sign567Z = -1
      if angleVector < 0: # y > 0 and z < 0
        # point 1, 2, 3 has y decrease, z increase
        sign123Y = -1
        sign123Z = 1
        # point 5, 6, 7 has y increase, z decrease
        sign567Y = 1
        sign567Z = -1   
      stepY = deviation*sin(abs(angleVector))
      stepZ = deviation*cos(abs(angleVector))
      
    if abs(angleVector) > pi/2:  
      if angleVector > 0:   
        # point 1, 2, 3 has y increase, z decrease
        sign123Y = 1
        sign123Z = -1
        # point 5, 6, 7 has y decrease, z increase
        sign567Y = -1
        sign567Z = 1
      if angleVector < 0:
        # point 1, 2, 3 has y decrease, z decrease
        sign123Y = -1
        sign123Z = -1
        # point 5, 6, 7 has y increase, z increase
        sign567Y = 1
        sign567Z = 1
      stepY = deviation*cos(abs(angleVector)- pi/2)
      stepZ = deviation*sin(abs(angleVector) -pi/2)   
      
    corPnt1 = coordinatePoint(self.endEffector.X      , self.endEffector.Y + 3*stepY*sign123Y, self.endEffector.Z + 3*stepZ*sign123Z)
    corPnt2 = coordinatePoint(self.endEffector.X      , self.endEffector.Y + 2*stepY*sign123Y, self.endEffector.Z + 2*stepZ*sign123Z)
    corPnt3 = coordinatePoint(self.endEffector.X      , self.endEffector.Y +  stepY*sign123Y , self.endEffector.Z +   stepZ*sign123Z)
    corPnt4 = coordinatePoint(self.endEffector.X      , self.endEffector.Y                   , self.endEffector.Z                   )
    corPnt5 = coordinatePoint(self.endEffector.X      , self.endEffector.Y +  stepY*sign567Y , self.endEffector.Z +   stepZ*sign567Z)
    corPnt6 = coordinatePoint(self.endEffector.X      , self.endEffector.Y + 2*stepY*sign567Y, self.endEffector.Z + 2*stepZ*sign567Z)
    corPnt7 = coordinatePoint(self.endEffector.X       , self.endEffector.Y + 3*stepY*sign567Y, self.endEffector.Z + 3*stepZ*sign567Z)
    corPnt8 = coordinatePoint(self.endEffector.X+ high, self.endEffector.Y                   , self.endEffector.Z                   )
    

    posPnt1 = self.backwardKinematic(corPnt1.getCoordinate())
    posPnt2 = self.backwardKinematic(corPnt2.getCoordinate())
    posPnt3 = self.backwardKinematic(corPnt3.getCoordinate())
    posPnt4 = self.backwardKinematic(corPnt4.getCoordinate())
    posPnt5 = self.backwardKinematic(corPnt5.getCoordinate())
    posPnt6 = self.backwardKinematic(corPnt6.getCoordinate())
    posPnt7 = self.backwardKinematic(corPnt7.getCoordinate())
    posPnt8 = self.backwardKinematic(corPnt8.getCoordinate())
    
    # return [corPnt1, corPnt2, corPnt3, corPnt4, corPnt5, corPnt6, corPnt7, corPnt8]
    return [posPnt1, posPnt2, posPnt3, posPnt4, posPnt5, posPnt6, posPnt7, posPnt8]
  
  def getPosModeStandNormal(self):
    posPnt = self.backwardKinematic(self.endEffector.getCoordinate())
    return posPnt
  
  def getPosModeStandUpDown(self, heightDeviation):
    currentPos = self.endEffector.getCoordinate()
    currentPos[0][0] += heightDeviation
    # check condition of currentPos[0][0]
    posPnt = self.backwardKinematic(currentPos.getCoordinate())
    return posPnt
  
#---------------------------------------------------------------------------------------------------------------------#