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

import time
import numpy as np
import rclpy

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
      
  # recalculate the point 4 of trajectory
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
  
  # get pos of each leg in point4
  def getPosCurrentAllLegs(self):
    self.posCurrentRR = self.legRR.getPosCurrentLeg()
    self.posCurrentRL = self.legRL.getPosCurrentLeg()
    self.posCurrentFR = self.legFR.getPosCurrentLeg()
    self.posCurrentFL = self.legFL.getPosCurrentLeg()
#---------------------------------------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------------------------------------#
# Class AdditionClientAsync: the class to initialize the service in ros2 to read the x, y from gamePad_node
class AdditionClientAsync(Node):
  def __init__(self):
    super().__init__("addition_client_async")
    self.client = self.create_client(GamepadSrv, "gamepad")
    while not self.client.wait_for_service(timeout_sec=1.0):
        self.get_logger().info("service not available, waiting again...")

  def send_request(self):
      request = GamepadSrv.Request()
      self.future = self.client.call_async(request)
      
  def get_position(self):
    self.send_request()
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


def main():
    rclpy.init()
    
    # declare object of GamePad, CAN, robotDogTeam
    serviceGamePadRos2= AdditionClientAsync()
    topicCANRos2  = PublishCommunication()
    robotDogTeam = quadrupedRobot()
    
    # start standup
    robotDogTeam.getPosCurrentAllLegs()
    
    # send message to CAN to control 4-leg of quadruped robot
    topicCANRos2.send_message(robotDogTeam.posCurrentRR, robotDogTeam.posCurrentRL, robotDogTeam.posCurrentFR, robotDogTeam.posCurrentFL)
    time.sleep(4)
    
    # declare the current index of each leg
    idxRR = 4
    idxRL = 4
    idxFR = 4
    idxFL = 4
    
    # declare the variable to store x, y which are extracted from gamePad
    newAngleGamePad  = np.inf
    oldAngleGamePad = newAngleGamePad
    
    while True:
      try:
        # check 4 legs contact with ground
        if (idxRR < 8) and (idxRL < 8) and (idxFR < 8) and (idxFL < 8):
          
          # read x, y from gamePad(todo)
          responseGamePad = serviceGamePadRos2.get_position()
          xGamePad = responseGamePad.position[0]
          yGamePad = responseGamePad.position[1]
          
          # joystick drop
          if (abs(xGamePad) < 0.1) and (abs(yGamePad) < 0.1):
            if (idxRR != 4) or (idxRL != 4) or (idxFR != 4) or (idxFL != 4):
              idxRR = 4
              idxRL = 4
              idxFR = 4
              idxFL= 4
              # CAN send message to move 4 leg to point4
              # move RL to 8 and to 4
              # move FR to 8 and to 4
              # move RR to 8 and to 4
              # move FL to 8 and to 4        
              topicCANRos2.send_message(robotDogTeam.posCurrentRR, robotDogTeam.posCurrentRL, robotDogTeam.posCurrentFR, robotDogTeam.posCurrentFL)
              time.sleep(1)
              oldAngleGamePad = np.inf
          # joystick is activating
          else:
            newAngleGamePad = atan2(-xGamePad, yGamePad)
            if oldAngleGamePad != newAngleGamePad:
              robotDogTeam.updatePosTrajectoryAllLegs(newAngleGamePad)
              if (idxRR != 4) and (idxRL != 4) and (idxFR != 4) and (idxFL != 4):
                topicCANRos2.send_message(robotDogTeam.posCurrentRR, robotDogTeam.posCurrentRL, robotDogTeam.posCurrentFR, robotDogTeam.posCurrentFL)
                time.sleep(1)
              idxRR = 5
              idxRL = 1
              idxFR = 7
              idxFL = 3
              # send message to CAN_node to control the pos of motor(motor) (todo)
              # CAN send message 
              # move FR to 8 and to 7
              # move FL to 8 and to 3
              # move RL to 8 and to 1
              # move RR to 8 and to 5
              topicCANRos2.send_message(robotDogTeam.trajectoryRRTemp[idxRR -1], robotDogTeam.trajectoryRLTemp[idxRL-1], robotDogTeam.trajectoryFRTemp[idxFR-1], robotDogTeam.trajectoryFLTemp[idxFL-1])
              time.sleep(1)
              oldAngleGamePad = newAngleGamePad
            else: 
              idxRR =  8 if (idxRR -1) < 1 else idxRR -1
              idxRL =  8 if (idxRL -1) < 1 else idxRL -1
              idxFR =  8 if (idxFR -1) < 1 else idxFR -1
              idxFL =  8 if (idxFL -1) < 1 else idxFL -1
              # send message to CAN_node to control the pos of motor(todo)
              topicCANRos2.send_message(robotDogTeam.trajectoryRRTemp[idxRR -1], robotDogTeam.trajectoryRLTemp[idxRL-1], robotDogTeam.trajectoryFRTemp[idxFR-1], robotDogTeam.trajectoryFLTemp[idxFL-1])
              time.sleep(1)
          # update x old and y old with x, y new
          # oldAngleGamePad = newAngleGamePad

        else:
          idxRR =  8 if (idxRR -1) < 1 else idxRR -1
          idxRL =  8 if (idxRL -1) < 1 else idxRL -1
          idxFR =  8 if (idxFR -1) < 1 else idxFR -1
          idxFL =  8 if (idxFL -1) < 1 else idxFL -1
          # CAN send message
          topicCANRos2.send_message(robotDogTeam.trajectoryRRTemp[idxRR -1], robotDogTeam.trajectoryRLTemp[idxRL-1], robotDogTeam.trajectoryFRTemp[idxFR-1], robotDogTeam.trajectoryFLTemp[idxFL-1])
          time.sleep(1)
      except KeyboardInterrupt:
        serviceGamePadRos2.destroy_node()
        topicCANRos2.destroy_node()
        rclpy.shutdown()
        
  
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
  