# * File: quadrupedRobot.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 17, 2024
# * Last Modified: October 17, 2024
# * Description: the program to control all operations of robot
# * Status: developing (Done, brainStorm, developing):


from controller.kinematicRobot import coordinatePoint, kinematicEachLeg
from controller.convertGlobal2LocalCoordinate import leg
from custom_interfaces.srv import GamepadSrv
from math import atan2, cos, sin, pi
from rclpy.node import Node
from custom_interfaces.msg import PublishMessage
from enum import Enum

import time
import numpy as np
import rclpy

#---------------------------------------------------------------------------------------------------------------------#
# Class modeControl: define several modes of quadruped robot in operating
# Parameters:
#     - standUp: this mode to control quadruped robot stand up
#     - standDown: this mode to control the quadruped robot stand down
#     - standNormal: this mode to control the quadruped robot stand balance
#     - move: this mode to control the quadruped robot move according any direction
class modeControl(Enum):
  standUpDown         = 0
  standNormal         = 1
  move                = 2
#---------------------------------------------------------------------------------------------------------------------#


# Class AdditionClientAsync: the class to initialize the service in ros2 to read the x, y from gamePad_node
class AdditionClientAsync(Node):
  def __init__(self):
    super().__init__("addition_client_async")
    self.client = self.create_client(GamepadSrv, "gamepad")
    while not self.client.wait_for_service(timeout_sec=1.0):
        self.get_logger().info("service not available, waiting again...")

  def sendRequest(self):
      request = GamepadSrv.Request()
      self.future = self.client.call_async(request)
      
  def getInformFromGamePad(self):
    self.sendRequest()
    while rclpy.ok():
      rclpy.spin_once(self)
      if self.future.done():
          try:
              response = self.future.result()
          except Exception as e:
              self.get_logger().info(
                  f"Service call failed {e}"
              )
          else:
              self.get_logger().info(  
                  f"Result of addition is {response.position}"
              )
              break
    return response
#---------------------------------------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------------------------------------#
# Class PublishCommunication: the class to initialize the topic in ros2 to send message to CAN_node
class PublishCommunication(Node):
  def __init__(self):
    super().__init__("PublisherNode")
    self.publisher_ = self.create_publisher(PublishMessage, 'publishTopic', 10)

  def send_message(self, trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL):
    msg = PublishMessage()
    msg.namerr = "RR"
    msg.positionrr = trajectoryRR
    msg.namerl = "RL"
    msg.positionrl = trajectoryRL
    msg.namefr = "FR"
    msg.positionfr = trajectoryFR
    msg.namefl = "RL"
    msg.positionfl = trajectoryFL

    # send message to the CAN node
    self.publisher_.publish(msg)
#---------------------------------------------------------------------------------------------------------------------#


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
    self.globalCoordinateStartingRR = coordinatePoint(-290, -161.12, 187)
    self.globalCoordinateStartingRL = coordinatePoint(-290, 161.12, 187) 
    self.globalCoordinateStartingFR = coordinatePoint(-290, -161.12, -187) 
    self.globalCoordinateStartingFL = coordinatePoint(-290, 161.12, -187)    

    self.legRR = kinematicEachLeg(self.globalCoordinateStartingRR, leg.RR.value)
    self.legRL = kinematicEachLeg(self.globalCoordinateStartingRL, leg.RL.value)
    self.legFR = kinematicEachLeg(self.globalCoordinateStartingFR, leg.FR.value)
    self.legFL = kinematicEachLeg(self.globalCoordinateStartingFL, leg.FL.value)
    
    self.heightStandUpDownDeviation = 0
    
  def createHomoMatrixBalance(self, pitch, yaw):
    rotateMatrixPitch = np.array([[cos(pitch), 0, sin(pitch), 0],
                              [0, 1, 0, 0],
                              [-sin(pitch), 0, cos(pitch), 0],
                              [0, 0, 0, 1]], dtype= np.float64)
  
    rotateMatrixYaw = np.array([[cos(yaw), -sin(yaw), 0, 0],
                              [sin(yaw), cos(yaw), 0, 0],
                              [0, 0, 1, 0],
                              [0, 0, 0, 1]], dtype= np.float64)

    return np.linalg.inv(rotateMatrixYaw.dot(rotateMatrixPitch))
  
  def updatePosTrajectoryAllLegs(self, vectorAngle):
    # the result of posTrajectoryRR has foramt: [[], [], [], [], [], [], [], []]
    posTrajectoryRR = self.legRR.updatePosTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    posTrajectoryRL = self.legRL.updatePosTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    posTrajectoryFR = self.legFR.updatePosTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    posTrajectoryFL = self.legFL.updatePosTrajectoryLeg(deviation = 35, angleVector= vectorAngle)

    self.trajectoryRRTemp = posTrajectoryRR      
    self.trajectoryRLTemp = posTrajectoryRL
    self.trajectoryFRTemp = posTrajectoryFR
    self.trajectoryFLTemp = posTrajectoryFL
    
    # if abs(vectorAngle) <= atan2(161.12, 187):
    #   self.trajectoryRRTemp = posTrajectoryRR      
    #   self.trajectoryRLTemp = posTrajectoryRL
    #   self.trajectoryFRTemp = posTrajectoryFR
    #   self.trajectoryFLTemp = posTrajectoryFL
    
    # else:
    #   if abs(vectorAngle) <= (pi - atan2(161.12, 187)):
    #     if vectorAngle < 0:
    #       self.trajectoryRRTemp = posTrajectoryFR
    #       self.trajectoryRLTemp = posTrajectoryRR
    #       self.trajectoryFRTemp = posTrajectoryFL
    #       self.trajectoryFLTemp = posTrajectoryRL
    #     else:
    #       self.trajectoryRRTemp = posTrajectoryRL
    #       self.trajectoryRLTemp = posTrajectoryFL
    #       self.trajectoryFRTemp = posTrajectoryRR
    #       self.trajectoryFLTemp = posTrajectoryFR
    #   else:
    #     self.trajectoryRRTemp = posTrajectoryFL
    #     self.trajectoryRLTemp = posTrajectoryFR
    #     self.trajectoryFRTemp = posTrajectoryRL
    #     self.trajectoryFLTemp = posTrajectoryRR
      
  def selfBalancingIMU(self, pitch, yaw):
    # check the angle of pitch or yaw is exceed or not (threshold = 5 degrees)
    if (abs(pitch) > pi/36) or (abs(yaw) > pi/36):
      balanceMatrix = self.createHomoMatrixBalance(pitch, yaw)
      # convert all coordinates of leg to new coordinate system
      imuGlobalCoordinateRR = balanceMatrix.dot(self.legRR.endEffector.getCoordinate()).reshape(1, -1)
      imuGlobalCoordinateRL = balanceMatrix.dot(self.legRL.endEffector.getCoordinate()).reshape(1, -1)
      imuGlobalCoordinateFR = balanceMatrix.dot(self.legFR.endEffector.getCoordinate()).reshape(1, -1)
      imuGlobalCoordinateFL = balanceMatrix.dot(self.legFL.endEffector.getCoordinate()).reshape(1, -1)
      
      print("global endEffector of each foot before balancing!!!")
      print("RR: ", self.legRR.endEffector.getCoordinate().reshape(1, -1))
      print("RL: ", self.legRL.endEffector.getCoordinate().reshape(1, -1))
      print("FR: ", self.legFR.endEffector.getCoordinate().reshape(1, -1))
      print("FL: ", self.legFL.endEffector.getCoordinate().reshape(1, -1))
      
      # update the new the new position of endEffector
      self.legRR.updatePositionEndEffector(imuGlobalCoordinateRR)
      self.legRL.updatePositionEndEffector(imuGlobalCoordinateRL)
      self.legFR.updatePositionEndEffector(imuGlobalCoordinateFR)
      self.legFL.updatePositionEndEffector(imuGlobalCoordinateFL)
    
    
      
      print("global endEffector of each foot after balancing!!!")
      print("RR: ", self.legRR.endEffector.getCoordinate().reshape(1, -1))
      print("RL: ", self.legRL.endEffector.getCoordinate().reshape(1, -1))
      print("FR: ", self.legFR.endEffector.getCoordinate().reshape(1, -1))
      print("FL: ", self.legFL.endEffector.getCoordinate().reshape(1, -1))
      print("############################")
      return "Modified"
    else:
      return "not modified"
  
  def modeControlStandNormalAllLegs(self):
    if self.currentMode == modeControl.move.value or self.currentMode == modeControl.standNormal.value:
      self.posCurrentRR = self.legRR.getPosModeStandNormal()
      self.posCurrentRL = self.legRL.getPosModeStandNormal()
      self.posCurrentFR = self.legFR.getPosModeStandNormal()
      self.posCurrentFL = self.legFL.getPosModeStandNormal()
      
      self.idxRR = 4
      self.idxRL = 4
      self.idxFR = 4
      self.idxFL = 4
    
      if (not self.posCurrentRR) and (not self.posCurrentRL) and (not self.posCurrentFR) and (not self.posCurrentFL):
        self.topicCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
        time.sleep(postpone)
        self.currentMode = modeControl.standNormal.value
      return
    
    if self.currentMode == modeControl.standUpDown.value:
      if self.heightStandUpDownDeviation < 0:
        while self.heightStandUpDownDeviation < 0:
          self.heightStandUpDownDeviation += 20
          self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          if (not self.posCurrentRR) and (not self.posCurrentRL) and (not self.posCurrentFR) and (not self.posCurrentFL):
            self.topicCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
            time.sleep(postpone)
      
      if self.heightStandUpDownDeviation > 0:
        while self.heightStandUpDownDeviation > 0:
          self.heightStandUpDownDeviation -= 20
          self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          if (not self.posCurrentRR) and (not self.posCurrentRL) and (not self.posCurrentFR) and (not self.posCurrentFL):
            self.topicCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
            time.sleep(postpone)
      self.currentMode = modeControl.standNormal.value
      return

  def modeControlStandUpDownAllLegs(self, Up, Down):
    if self.currentMode == modeControl.move.value:
      self.modeControlStandNormalAllLegs()
      return
      
    if self.currentMode == modeControl.standUpDown.value or self.currentMode == modeControl.standNormal.value:
      if Up == 1:
        self.heightStandUpDownDeviation -= 20
      if Down== 1:
        self.heightStandUpDownDeviation += 20
        
      self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      
      if (not self.posCurrentRR) and (not self.posCurrentRL) and (not self.posCurrentFR) and (not self.posCurrentFL):
        self.topicCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
        time.sleep(postpone)
        self.currentMode = modeControl.standUpDown.value
      else:
        if Up == 1:
          self.heightStandUpDownDeviation += 20
        if Down == 1:
          self.heightStandUpDownDeviation -= 20
        
      return
  
  def modeControlMove(self, xGamePad, yGamePad):
    if self.currentMode == modeControl.move.value:
      self.newAngleGamePad = atan2(-xGamePad, yGamePad)
      if abs(self.newAngleGamePad - self.oldAngleGamePad) >= 25/180*pi:
        self.modeControlStandNormalAllLegs()
        self.oldAngleGamePad = self.newAngleGamePad
      else: 
        self.idxRR =  8 if (self.idxRR -1) < 1 else self.idxRR -1
        self.idxRL =  8 if (self.idxRL -1) < 1 else self.idxRL -1
        self.idxFR =  8 if (self.idxFR -1) < 1 else self.idxFR -1
        self.idxFL =  8 if (self.idxFL -1) < 1 else self.idxFL -1
        self.topicCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
        time.sleep(postponse)
        
        idxRR =  8 if (idxRR -1) < 1 else idxRR -1
        idxRL =  8 if (idxRL -1) < 1 else idxRL -1
        idxFR =  8 if (idxFR -1) < 1 else idxFR -1
        idxFL =  8 if (idxFL -1) < 1 else idxFL -1
        self.topicCANRos2.send_message(self.trajectoryRRTemp[idxRR -1], self.trajectoryRLTemp[idxRL-1], self.trajectoryFRTemp[idxFR-1], self.trajectoryFLTemp[idxFL-1])
        time.sleep(postponse)
    
    if self.currentMode == modeControl.standNormal.value:
      vectorAngle = atan2(-xGamePad, yGamePad)
      self.updatePosTrajectoryAllLegs(vectorAngle)
      self.oldAngleGamePad = vectorAngle
      
      self.idxRR = 5
      self.idxRL = 1
      self.idxFR = 7
      self.idxFL = 3
      self.topicCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
      time.sleep(postpone)
      self.currentMode = modeControl.move.value
      return

    if self.currentMode == modeControl.standUpDown.value:
      self.modeControlStandNormalAllLegs()
      return
    
  def modeMove(self, responseGamePad):
    xGamePad = responseGamePad.position[0]
    yGamePad = responseGamePad.position[1]
    # joystick drop
     # check 4 legs contact with ground
        if (self.idxRR < 8) and (self.idxRL < 8) and (self.idxFR < 8) and (self.idxFL < 8):
          
          # read x, y from gamePad(todo)
          responseGamePad = self.serviceGamePadRos2.get_position()
    if (abs(xGamePad) < 0.1) and (abs(yGamePad) < 0.1):
      if (self.idxRR != 4) or (self.idxRL != 4) or (self.idxFR != 4) or (self.idxFL != 4):
        self.idxRR = 4
        self.idxRL = 4
        self.idxFR = 4
        self.idxFL= 4
        # CAN send message to move 4 leg to point4
        # move RL to 8 and to 4
        # move FR to 8 and to 4
        # move RR to 8 and to 4
        # move FL to 8 and to 4        
        self.topicCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
        time.sleep(0.1)
        oldAngleGamePad = np.inf
    # joystick is activating
    else:
      newAngleGamePad = atan2(-xGamePad, yGamePad)
      if abs(newAngleGamePad - oldAngleGamePad) >= 25/180*pi:
        self.updatePosTrajectoryAllLegs(newAngleGamePad)
        if (self.idxRR != 4) and (self.idxRL != 4) and (self.idxFR != 4) and (self.idxFL != 4):
          self.topicCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
          time.sleep(0.1)
        self.idxRR = 5
        self.idxRL = 1
        self.idxFR = 7
        self.idxFL = 3
        # send message to CAN_node to control the pos of motor(motor) (todo)
        # CAN send message 
        # move FR to 8 and to 7
        # move FL to 8 and to 3
        # move RL to 8 and to 1
        # move RR to 8 and to 5
        self.topicCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
        time.sleep(0.1)
        oldAngleGamePad = newAngleGamePad
      else: 
        self.idxRR =  8 if (self.idxRR -1) < 1 else self.idxRR -1
        self.idxRL =  8 if (self.idxRL -1) < 1 else self.idxRL -1
        self.idxFR =  8 if (self.idxFR -1) < 1 else self.idxFR -1
        self.idxFL =  8 if (self.idxFL -1) < 1 else self.idxFL -1
        # send message to CAN_node to control the pos of motor(todo)
        self.topicCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
        time.sleep(0.1)
    # update x old and y old with x, y new
    # oldAngleGamePad = newAngleGamePad

  def operation(self):
    buttonStandUp = 1     # standUp
    buttonStandDown = 0   # standDown
    buttonStandNormal = 1 # standNormal
    joyX = 0.1
    joyY = 0.4
    
    rclpy.init()
    self.serviceGamePadRos2= AdditionClientAsync()
    self.topicCANRos2  = PublishCommunication()

    # the first mode when turning on the quadruped robot
    self.currentMode = modeControl.standNormal.value
    self.modeControlStandNormalAllLegs()
    while True:
      try:
        responseGamePad = self.serviceGamePadRos2.getInformFromGamePad()
        responseGamePad = [buttonStandUp, buttonStandDown, buttonStandNormal, joyX, joyY]
        # condition to check responseGamePad is button A or B or x or y, which are received from gamePad
        if responseGamePad[0] == 1:
          self.modeControlStandUpDownAllLegs(Up = 1, Down = 0)
        else: # standUp = 0
          if responseGamePad[1]== 1:
            self.modeControlStandUpDownAllLegs(Up = 0, Down = 1)
          else: # standDown = 0
            if responseGamePad[2] == 1:
              self.modeControlStandNormalAllLegs()
            else: # standNormal = 0
              xGamePad = responseGamePad[3]
              yGamePad = responseGamePad[4]
              if (abs(xGamePad) >= 0.2) or (abs(yGamePad) >= 0.2):
                self.modeControlMove(xGamePad, yGamePad)
              else: # xGamePad = 0 and yGamePad = 0
                pass
      except KeyboardInterrupt:
        self.serviceGamePadRos2.destroy_node()
        self.topicCANRos2.destroy_node()
        rclpy.shutdown()

#---------------------------------------------------------------------------------------------------------------------#



def main():
  robotDogTeam = quadrupedRobot()
  robotDogTeam.operation()
if __name__ == "__main__":
  main()
  