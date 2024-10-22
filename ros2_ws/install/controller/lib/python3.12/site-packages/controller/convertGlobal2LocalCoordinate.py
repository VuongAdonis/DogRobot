# * File: convertGlobal2LocalCoordinate.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 08, 2024
# * Last Modified: October 17, 2024
# * Description: declare and define some matrixes to change the coordinate of original system to
#    the coordinate corresponding of 4-leg of robot (local coordinate)
# * Status: Done (Done, brainStorm, developing):
#       - 

# import necessary framework
import numpy as np
from math import cos, sin, pi
from enum import Enum

#---------------------------------------------------------------------------------------------------------------------#
# Class leg: declare the leg (enum) to distinguish 4-leg of quadruped robot
class leg(Enum):
  FR                  = 1
  FL                  = 2
  RR                  = 3
  RL                  = 4
#---------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------#
# Class's name:
#   - homoMatrix 
# Description:
#   - Declare and define some functions to convert global coordinate to global coordinate for each leg in quadrupedRobot
class homoMatrix:
  
  def __init__(self):
    self.createHomoMatrixRR()
    self.createHomoMatrixRL()
    self.createHomoMatrixFR()
    self.createHomoMatrixFL()
    
  def createHomoMatrixRR(self):
    self.homoMatrixRR= np.linalg.inv(np.array([[1, 0, 0, 0],
                                              [0, 1, 0, -75],
                                              [0, 0, 1, 52.9],
                                              [0, 0, 0, 1]], dtype= np.float64))
  
  def createHomoMatrixFL(self):
    transformMatrixFL = np.array([[1, 0, 0, 0],
                                [0, 1, 0, 75],
                                [0, 0, 1, -52.9],
                                [0, 0, 0, 1]], dtype= np.float64)
    rotateMatrixFL = np.array([[1, 0, 0, 0],
                             [0, cos(pi), -sin(pi), 0],
                             [0, sin(pi), cos(pi), 0],
                             [0, 0, 0, 1]])
    self.homoMatrixFL = np.linalg.inv(transformMatrixFL.dot(rotateMatrixFL))
    
  def createHomoMatrixRL(self):
    transformMatrixRL = np.array([[1, 0, 0, 0],
                                [0, 1, 0, 75],
                                [0, 0, 1, 52.9],
                                [0, 0, 0, 1]], dtype= np.float64)
    rotateMatrixRL = np.array([[cos(pi), -sin(pi), 0, 0],
                             [sin(pi), cos(pi), 0, 0],
                             [0, 0, 1, 0],
                             [0, 0, 0, 1]], dtype= np.float64)
    
    self.homoMatrixRL= np.linalg.inv(transformMatrixRL.dot(rotateMatrixRL))
    
  def createHomoMatrixFR(self):
    transformMatrixFR = np.array([[1, 0, 0, 0],
                                [0, 1, 0, -75],
                                [0, 0, 1, -52.9],
                                [0, 0, 0, 1]], dtype= np.float64)
    rotateMatrixFR = np.array([[cos(pi), 0, sin(pi), 0],
                             [0, 1, 0, 0],
                             [-sin(pi), 0, cos(pi), 0],
                             [0, 0, 0, 1]])
    self.homoMatrixFR = np.linalg.inv(transformMatrixFR.dot(rotateMatrixFR))

  def convertGlobal2LocalCoordinate(self, globalCoordinate, legType):
    localCoordinate = None
    if legType == leg.FL.value:
      localCoordinate = self.homoMatrixFL.dot(globalCoordinate)
    if legType == leg.FR.value:
      localCoordinate = self.homoMatrixFR.dot(globalCoordinate)
    if legType == leg.RR.value:
      localCoordinate = self.homoMatrixRR.dot(globalCoordinate)
    if legType == leg.RL.value:
      localCoordinate = self.homoMatrixRL.dot(globalCoordinate)
    return localCoordinate
#---------------------------------------------------------------------------------------------------------------------#
    