# * File: quadrupedRobot.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 17, 2024
# * Last Modified: October 17, 2024
# * Description: the program to control all operations of robot
# * Status: developing (Done, brainStorm, developing):


from kinematicRobot import coordinatePoint, kinematicEachLeg
from convertGlobal2LocalCoordinate import leg
import sys
sys.path.append("../../can_node/can_node")
from canController import CanNode
import time
from math import pi, atan2


#---------------------------------------------------------------------------------------------------------------------#
# Class quadrupedRobot: the main class to control all operations of quadruped robot
# Parameters:
#    - globalCoordinateFL: global coordinate of FL leg
#    - globalCoordinateFR: global coordinate of FR leg
#    - globalCoordinateRR: global coordinate of RR leg
#    - globalCoordinateRL: global coordinate of RL leg
#    - legFL: the object is on behalf of leg front left 
#    - legFR: the object is on behalf of leg front right
#    - legRR: the object is on behalf of leg rear right
#    - legRL: the object is on behalf of leg rear left   
class quadrupedRobot:
  
  def __init__(self):
    # may be modified x and z, not y
    globalCoordinateFL = coordinatePoint(-330, 161.12, -187)    
    globalCoordinateFR = coordinatePoint(-330, -161.12, -187) 
    globalCoordinateRL = coordinatePoint(-330, 161.12, 187) 
    globalCoordinateRR = coordinatePoint(-330, -161.12, 187)
    
    self.legFL = kinematicEachLeg(globalCoordinateFL, leg.FL.value)
    self.legRR = kinematicEachLeg(globalCoordinateRR, leg.RR.value)
    self.legRL = kinematicEachLeg(globalCoordinateRL, leg.RL.value)
    self.legFR = kinematicEachLeg(globalCoordinateFR, leg.FR.value)
    
  def updateTrajectoryAllLegs(self, vectorAngle):
    self.trajectoryRROriginal = self.legRR.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    self.trajectoryRLOriginal = self.legRL.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    self.trajectoryFROriginal = self.legFR.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    self.trajectoryFLOriginal = self.legFL.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    
    # if abs(vectorAngle) <= atan2(161.12, 187):
    #   self.trajectoryRRTemp = trajectoryRROriginal      
    #   self.trajectoryRLTemp = trajectoryRLOriginal
    #   self.trajectoryFRTemp = trajectoryFROriginal
    #   self.trajectoryFLTemp = trajectoryFLOriginal
    
    # else:
    #   if abs(vectorAngle) <= (pi - atan2(161.12, 187)):
    #     if vectorAngle < 0:
    #       self.trajectoryRRTemp = trajectoryFROriginal
    #       self.trajectoryRLTemp = trajectoryRROriginal
    #       self.trajectoryFRTemp = trajectoryFLOriginal
    #       self.trajectoryFLTemp = trajectoryRLOriginal
    #     else:
    #       self.trajectoryRRTemp = trajectoryRLOriginal
    #       self.trajectoryRLTemp = trajectoryFLOriginal
    #       self.trajectoryFRTemp = trajectoryRROriginal
    #       self.trajectoryFLTemp = trajectoryFROriginal
    #   else:
    #     self.trajectoryRRTemp = trajectoryFLOriginal
    #     self.trajectoryRLTemp = trajectoryFROriginal
    #     self.trajectoryFRTemp = trajectoryRLOriginal
    #     self.trajectoryFLTemp = trajectoryRROriginal
        
  def getTrajectory(self):
    return self.trajectoryRROriginal, self.trajectoryRLOriginal, self.trajectoryFROriginal, self.trajectoryFLOriginal
    # return self.trajectoryRRTemp, self.trajectoryRLTemp, self.trajectoryFRTemp, self.trajectoryFLTemp
#---------------------------------------------------------------------------------------------------------------------#


def main():
  angleVector = 0   # updated from the gamePad
  robotDogTeam = quadrupedRobot()
    
  robotDogTeam.updateTrajectoryAllLegs(angleVector)
  trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL = robotDogTeam.getTrajectory()
  print("----------------TRAJECTORY-----------------")
  for i in range(len(trajectoryRR)):
    print("-------------point", i+ 1, "------------------")
    print("RR:", trajectoryRR[i])
    # print("RL:", trajectoryRL[i])
    # print("FR:", trajectoryFR[i])
    # print("FL:", trajectoryFL[i])
  print("#############################################")
      
      
    
  # CAN = CanNode()
  # CAN.sendClosedLoop(5)
  # time.sleep(1)
  # CAN.sendClosedLoop(4)
  # time.sleep(1)
  # CAN.sendClosedLoop(1)
  # time.sleep(1)
  # CAN.sendClosedLoop(2)
  # time.sleep(1)
  # try:
  #   idxRR = 4
  #   idxFR = 6
  #   while True:
      
  #     CAN.sendPos(5, trajectoryFR[idxFR][2])
  #     time.sleep(1)
  #     CAN.sendPos(4, trajectoryFR[idxFR][1])
  #     time.sleep(1)
  #     CAN.sendPos(2, trajectoryRR[idxRR][1])
  #     time.sleep(1)
  #     CAN.sendPos(1, trajectoryRR[idxRR][2])
  #     time.sleep(1)
  #     idxRR -= 1
  #     idxFR -= 1
  #     if idxRR < 0:
  #       idxRR = 7
  #     if idxFR < 0:
  #       idxFR = 7

  # except KeyboardInterrupt:
  #   CAN.sendIdle(5)
  #   time.sleep(1)
  #   CAN.sendIdle(4)
  #   time.sleep(1)
  #   CAN.sendIdle(1)
  #   time.sleep(1)
  #   CAN.sendIdle(2)
  #   time.sleep(1)
  #   CAN.bus.shutdown()
  


if __name__ == "__main__":
  main()
  