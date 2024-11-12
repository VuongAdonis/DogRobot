# * File: quadrupedRobot.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 17, 2024
# * Last Modified: October 30, 2024
# * Description: the program to control all operations of robot
# * Status: developing (Done, brainStorm, developing):


from controller.kinematicRobot import coordinatePoint, kinematicEachLeg
from controller.convertGlobal2LocalCoordinate import leg
from math import atan2, cos, sin, pi
from rclpy.node import Node
from custom_interfaces.msg import PublishMessage
from custom_interfaces.srv import GamepadSrv
# from custom_interfaces.srv import IMU
from custom_interfaces.srv import CANsrv
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

# define the time sleep for control leg robot
postpone = 0.25

# Class AdditionClientAsync: the class to initialize the service in ros2 to read the input from gamePad_node
class AdditionClientAsync(Node):
  def __init__(self):
    super().__init__("addition_client_async")
    self.client = self.create_client(GamepadSrv, "gamepad")
    while not self.client.wait_for_service(timeout_sec=1.0):
        self.get_logger().info("service for gamepad not available, waiting again...")

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
                  f"Result of gamepad is {response.position}"
              )
              break
    return response
#---------------------------------------------------------------------------------------------------------------------#
# Class IMUClientAsync: the class to initialize the service in ros2 to read the input from IMU
# class IMUClientAsync(Node):
#     def __init__(self):
#         super().__init__("imu_client_async")
#         self.client = self.create_client(IMU, "imusrv")
#         while not self.client.wait_for_service(timeout_sec=1.0):
#             self.get_logger().info("service for imu not available, waiting again...")

#     def send_request(self):
#         request = IMU.Request()
#         # request.a = int(sys.argv[1])
#         # request.b = int(sys.argv[2])
#         self.future = self.client.call_async(request)
    
#     def getInFormFromIMU(self):
#       self.sendRequest()
#       while rclpy.ok():
#         rclpy.spin_once(self)
#         if self.future.done():
#             try:
#                 response = self.future.result()
#             except Exception as e:
#                 self.get_logger().info(
#                     f"Service call failed {e}"
#                 )
#             else:
#                 self.get_logger().info(  
#                     f"Result of IMU is {response}"
#                 )
#                 break
#       return response
    
# Class CANClientAsync: the class to initialize the service in ros2 to communication with CAN
class CANClientAsync(Node):
    def __init__(self):
        super().__init__("can_client_async")
        self.client = self.create_client(CANsrv, "cansrv")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service for CAN not available, waiting again...")

    def send_message(self, trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL):
        request = CANsrv.Request()
        request.namerr = "RR"
        request.positionrr = trajectoryRR
        request.namerl = "RL"
        request.positionrl = trajectoryRL
        request.namefr = "FR"
        request.positionfr = trajectoryFR
        request.namefl = "FL"
        request.positionfl = trajectoryFL
        self.future = self.client.call_async(request)
        self.getInformFromCAN()
    
    def getInformFromCAN(self):
      # self.sendRequest()
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
                    f"Result of CAN is {response}"
                )
                break
      return response
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
    self.globalCoordinateStartingRR = coordinatePoint(-320, -161.12, 187)
    self.globalCoordinateStartingRL = coordinatePoint(-320, 161.12, 187) 
    self.globalCoordinateStartingFR = coordinatePoint(-320, -161.12, -187) 
    self.globalCoordinateStartingFL = coordinatePoint(-320, 161.12, -187)    

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
    posTrajectoryRR = self.legRR.updatePosTrajectoryLeg(deviation = 25, angleVector= vectorAngle)
    posTrajectoryRL = self.legRL.updatePosTrajectoryLeg(deviation = 25, angleVector= vectorAngle)
    posTrajectoryFR = self.legFR.updatePosTrajectoryLeg(deviation = 25, angleVector= vectorAngle)
    posTrajectoryFL = self.legFL.updatePosTrajectoryLeg(deviation = 25, angleVector= vectorAngle)

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
    
      if ( self.posCurrentRR) and ( self.posCurrentRL) and ( self.posCurrentFR) and ( self.posCurrentFL):
        self.serviceCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
        time.sleep(postpone)
        self.currentMode = modeControl.standNormal.value
      return
    
    if self.currentMode == modeControl.standUpDown.value:
      if self.heightStandUpDownDeviation < 0:
        while self.heightStandUpDownDeviation < 0:
          self.heightStandUpDownDeviation += 5
          self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          if ( self.posCurrentRR) and ( self.posCurrentRL) and ( self.posCurrentFR) and ( self.posCurrentFL):
            self.serviceCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
            time.sleep(postpone)
      
      if self.heightStandUpDownDeviation > 0:
        while self.heightStandUpDownDeviation > 0:
          self.heightStandUpDownDeviation -= 5
          self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          if ( self.posCurrentRR) and ( self.posCurrentRL) and ( self.posCurrentFR) and ( self.posCurrentFL):
            self.serviceCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
            time.sleep(postpone)
      self.currentMode = modeControl.standNormal.value
      return

  def modeControlStandUpDownAllLegs(self, Up, Down):
    if self.currentMode == modeControl.move.value:
      self.modeControlStandNormalAllLegs()
      return
      
    if self.currentMode == modeControl.standUpDown.value or self.currentMode == modeControl.standNormal.value:
      if Up == 1:
        self.heightStandUpDownDeviation -= 5
      if Down== 1:
        self.heightStandUpDownDeviation += 5
        
      self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
      # print("height: ", self.heightStandUpDownDeviation)
      if ( self.posCurrentRR) and ( self.posCurrentRL) and ( self.posCurrentFR) and ( self.posCurrentFL):
        self.serviceCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
        time.sleep(postpone)
        self.currentMode = modeControl.standUpDown.value
      else:
        if Up == 1:
          self.heightStandUpDownDeviation += 5
        if Down == 1:
          self.heightStandUpDownDeviation -= 5
        
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
        self.serviceCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
        time.sleep(postpone)
        
        self.idxRR =  8 if (self.idxRR -1) < 1 else self.idxRR -1
        self.idxRL =  8 if (self.idxRL -1) < 1 else self.idxRL -1
        self.idxFR =  8 if (self.idxFR -1) < 1 else self.idxFR -1
        self.idxFL =  8 if (self.idxFL -1) < 1 else self.idxFL -1
        self.serviceCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
        time.sleep(postpone)
    
    if self.currentMode == modeControl.standNormal.value:
      vectorAngle = atan2(-xGamePad, yGamePad)
      self.updatePosTrajectoryAllLegs(vectorAngle)
      self.oldAngleGamePad = vectorAngle
      
      self.idxRR = 5
      self.idxRL = 1
      self.idxFR = 7
      self.idxFL = 3
      self.serviceCANRos2.send_message(self.trajectoryRRTemp[self.idxRR -1], self.trajectoryRLTemp[self.idxRL-1], self.trajectoryFRTemp[self.idxFR-1], self.trajectoryFLTemp[self.idxFL-1])
      time.sleep(postpone)
      self.currentMode = modeControl.move.value
      return

    if self.currentMode == modeControl.standUpDown.value:
      self.modeControlStandNormalAllLegs()
      return
    
  

  def operation(self):
    buttonStandUp = 1     # standUp
    buttonStandDown = 0   # standDown
    buttonStandNormal = 1 # standNormal
    joyX = 0.1
    joyY = 0.4
    
    rclpy.init()
    self.serviceGamePadRos2 = AdditionClientAsync()
    # self.serviceIMURos2 = IMUClientAsync()
    self.serviceCANRos2 = CANClientAsync()

    # the first mode when turning on the quadruped robot
    self.currentMode = modeControl.standNormal.value
    self.modeControlStandNormalAllLegs()
    time.sleep(4)
    while True:
      try:
        responseGamePad = self.serviceGamePadRos2.getInformFromGamePad()
        # condition to check responseGamePad is button A or B or x or y, which are received from gamePad
        buttonStandUp = responseGamePad.button_stand_up     # standUp
        buttonStandDown = responseGamePad.button_stand_down   # standDown
        buttonStandNormal = responseGamePad.button_stand_normal # standNormal
        joyX = responseGamePad.position[0]
        joyY = responseGamePad.position[1]
        if buttonStandUp == 1:
          self.modeControlStandUpDownAllLegs(Up = 1, Down = 0)
        else: # standUp = 0
          if buttonStandDown == 1:
            self.modeControlStandUpDownAllLegs(Up = 0, Down = 1)
          else: # standDown = 0
            if buttonStandNormal == 1:
              self.modeControlStandNormalAllLegs()
            else: # standNormal = 0
              xGamePad = joyX
              yGamePad = joyY
              if (abs(xGamePad) >= 0.2) or (abs(yGamePad) >= 0.2):
                self.modeControlMove(xGamePad, yGamePad)
              else: # xGamePad = 0 and yGamePad = 0
                pass
      except KeyboardInterrupt:
        self.serviceGamePadRos2.destroy_node()
        self.serviceCANRos2.destroy_node()
        rclpy.shutdown()

#---------------------------------------------------------------------------------------------------------------------#



def main():
  robotDogTeam = quadrupedRobot()
  robotDogTeam.operation()
if __name__ == "__main__":
  main()
  