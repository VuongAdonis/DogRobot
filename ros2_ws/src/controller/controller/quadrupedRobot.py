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
from custom_interfaces.srv import IMU
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
postpone = 0

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
              # self.get_logger().info(  
              #     f"Result of gamepad is {response.position}"
              # )
              break
    return response
#---------------------------------------------------------------------------------------------------------------------#
# Class IMUClientAsync: the class to initialize the service in ros2 to read the input from IMU
class IMUClientAsync(Node):
    def __init__(self):
        super().__init__("imu_client_async")
        self.client = self.create_client(IMU, "imusrv")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service for imu not available, waiting again...")

    def send_request(self):
        request = IMU.Request()
        # request.a = int(sys.argv[1])
        # request.b = int(sys.argv[2])
        self.future = self.client.call_async(request)
    
    def getInFormFromIMU(self):
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
                    f"Result of IMU is {response}"
                )
                break
      return response
#---------------------------------------------------------------------------------------------------------------------#
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
    self.globalCoordinateStartingRR = coordinatePoint(-350, -161.12, 187)
    self.globalCoordinateStartingRL = coordinatePoint(-350, 161.12, 187) 
    self.globalCoordinateStartingFR = coordinatePoint(-350, -161.12, -187) 
    self.globalCoordinateStartingFL = coordinatePoint(-350, 161.12, -187)    

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
  
  def updatePosCurrentPointAllLegs(self, vectorAngle, idxRR, idxRL, idxFR, idxFL):
 
    self.posCurrentPointRR = self.legRR.updatePosCurrentPointLeg(deviation = 20, angleVector= vectorAngle, index= idxRR)
    self.posCurrentPointRL = self.legRL.updatePosCurrentPointLeg(deviation = 20, angleVector= vectorAngle, index= idxRL)
    self.posCurrentPointFR = self.legFR.updatePosCurrentPointLeg(deviation = 20, angleVector= vectorAngle, index= idxFR)
    self.posCurrentPointFL = self.legFL.updatePosCurrentPointLeg(deviation = 20, angleVector= vectorAngle, index= idxFL)
      
  def selfBalancingIMU(self, pitch, yaw):
    # pitch > 0 -> head up, pitch < 0 -> head down
    # yaw > 0 -> right down, raw < 0 -> right up
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
    # if self.currentMode == modeControl.move.value:
    #   self.currentMode = modeControl.standNormal.value
    #   return
    if  self.currentMode == modeControl.standNormal.value or self.currentMode == modeControl.move.value:
      self.posCurrentPointRR = self.legRR.getPosModeStandNormal()
      self.posCurrentPointRL = self.legRL.getPosModeStandNormal()
      self.posCurrentPointFR = self.legFR.getPosModeStandNormal()
      self.posCurrentPointFL = self.legFL.getPosModeStandNormal()
      
      self.idxRR = 4
      self.idxRL = 4
      self.idxFR = 4
      self.idxFL = 4
    
      if ( self.posCurrentPointRR) and ( self.posCurrentPointRL) and ( self.posCurrentPointFR) and ( self.posCurrentPointFL):
        self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
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
      
      if self.heightStandUpDownDeviation > 0:
        while self.heightStandUpDownDeviation > 0:
          self.heightStandUpDownDeviation -= 5
          self.posCurrentRR = self.legRR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentRL = self.legRL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFR = self.legFR.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          self.posCurrentFL = self.legFL.getPosModeStandUpDown(self.heightStandUpDownDeviation)
          if ( self.posCurrentRR) and ( self.posCurrentRL) and ( self.posCurrentFR) and ( self.posCurrentFL):
            self.serviceCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
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
        self.currentMode = modeControl.standUpDown.value
      else:
        if Up == 1:
          self.heightStandUpDownDeviation += 5
        if Down == 1:
          self.heightStandUpDownDeviation -= 5
        
      return
  
  def modeControlMove(self, xGamePad, yGamePad):
    deviationY = 1
    deviationZ = 1
    if self.currentMode == modeControl.move.value:
      self.vectorAngle = atan2(-xGamePad, yGamePad)
    
      if abs(self.vectorAngle - self.oldAngleGamePad) >= 25/180*pi:
        self.modeControlStandNormalAllLegs()
        self.oldAngleGamePad = self.vectorAngle
      else:   # angle  < 25/180*pi
        # send message to control body of robot to 
        angleGarvity = atan2(53.7, 62.3) # 53.7 and 62.3 is the coordinate of Garvity point of triangle

        self.idxRR = 19 if (self.idxRR -1) < 1 else self.idxRR -1
        self.idxRL = 19 if (self.idxRL -1) < 1 else self.idxRL -1
        self.idxFR = 19 if (self.idxFR -1) < 1 else self.idxFR -1
        self.idxFL = 19 if (self.idxFL -1) < 1 else self.idxFL -1
        self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
        for i in range(3, -1):
          self.serviceCANRos2.send_message(self.posCurrentPointRR[i], self.posCurrentPointRL[i], self.posCurrentPointFR[i], self.posCurrentPointFL[i])
          time.sleep(0.01)
        time.sleep(1)

        if (self.idxRL == 19 and self.idxFL == 2):# or (self.idxFL == 1 and self.idxFR == 3):
          for i in range (0, 70):
            # update Y
            self.legRR.endEffector.Y += deviationY*abs(sin(angleGarvity))
            self.legRL.endEffector.Y += deviationY*abs(sin(angleGarvity))
            self.legFR.endEffector.Y += deviationY*abs(sin(angleGarvity))
            self.legFL.endEffector.Y += deviationY*abs(sin(angleGarvity))
            # update Z 
            self.legRR.endEffector.Z += deviationZ*abs(cos(angleGarvity))
            self.legRL.endEffector.Z += deviationZ*abs(cos(angleGarvity))
            self.legFR.endEffector.Z += deviationZ*abs(cos(angleGarvity))
            self.legFL.endEffector.Z += deviationZ*abs(cos(angleGarvity))
            
            self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
            self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
        else:
          if (self.idxRR == 19 and self.idxFR == 2): #or (self.idxRL == 1 and self.idxRR == 3):
            for i in range(0, 70):
              # update Y
              self.legRR.endEffector.Y -= deviationY*abs(cos(angleGarvity))
              self.legRL.endEffector.Y -= deviationY*abs(cos(angleGarvity))
              self.legFR.endEffector.Y -= deviationY*abs(cos(angleGarvity))
              self.legFL.endEffector.Y -= deviationY*abs(cos(angleGarvity))
              
              # update Z 
              self.legRR.endEffector.Z += deviationZ*abs(sin(angleGarvity))
              self.legRL.endEffector.Z += deviationZ*abs(sin(angleGarvity))
              self.legFR.endEffector.Z += deviationZ*abs(sin(angleGarvity))
              self.legFL.endEffector.Z += deviationZ*abs(sin(angleGarvity))
              
              self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
              self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
          else:
            if (self.idxFL == 19 and self.idxRR == 2) :
              for i in range(0, 70):
                # update Y
                self.legRR.endEffector.Y += deviationY*abs(sin(angleGarvity))
                self.legRL.endEffector.Y += deviationY*abs(sin(angleGarvity))
                self.legFR.endEffector.Y += deviationY*abs(sin(angleGarvity))
                self.legFL.endEffector.Y += deviationY*abs(sin(angleGarvity))
                # update Z 
                self.legRR.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
                self.legRL.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
                self.legFR.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
                self.legFL.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
                
                self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
                self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
            else:
              if self.idxFR == 19 and self.idxRL == 2:
                for i in range (0, 70):
                  # update Y
                  self.legRR.endEffector.Y -= deviationY*abs(cos(angleGarvity))
                  self.legRL.endEffector.Y -= deviationY*abs(cos(angleGarvity))
                  self.legFR.endEffector.Y -= deviationY*abs(cos(angleGarvity))
                  self.legFL.endEffector.Y -= deviationY*abs(cos(angleGarvity))
                  
                  # update Z 
                  self.legRR.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                  self.legRL.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                  self.legFR.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                  self.legFL.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                  
                  self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
                  self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
        time.sleep(1)  

        # send message to control all legs of robot (1 leg raise)
        while self.idxRR > 8 or self.idxRL > 8 or self.idxFR > 8 or self.idxFL > 8:
          self.idxRR = self.idxRR if (self.idxRR -1) < 8 else self.idxRR -1
          self.idxRL = self.idxRL if (self.idxRL -1) < 8 else self.idxRL -1
          self.idxFR = self.idxFR if (self.idxFR -1) < 8 else self.idxFR -1
          self.idxFL = self.idxFL if (self.idxFL -1) < 8 else self.idxFL -1
          self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
          self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
          time.sleep(0.01)
        time.sleep(1)

        # send message to control body of robot to center
        if self.idxRL == 8 and self.idxFL == 2:
          for i in range (0, 70):
            # update Y
            self.legRR.endEffector.Y -= deviationY*abs(sin(angleGarvity))
            self.legRL.endEffector.Y -= deviationY*abs(sin(angleGarvity))
            self.legFR.endEffector.Y -= deviationY*abs(sin(angleGarvity))
            self.legFL.endEffector.Y -= deviationY*abs(sin(angleGarvity))
            # update Z 
            self.legRR.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
            self.legRL.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
            self.legFR.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
            self.legFL.endEffector.Z -= deviationZ*abs(cos(angleGarvity))
            
            self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
            self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])   
        else:
          if self.idxFL == 8 and self.idxRR == 2:
            for i in range(0, 70):
              # update Y
              self.legRR.endEffector.Y -= deviationY*abs(sin(angleGarvity))
              self.legRL.endEffector.Y -= deviationY*abs(sin(angleGarvity))
              self.legFR.endEffector.Y -= deviationY*abs(sin(angleGarvity))
              self.legFL.endEffector.Y -= deviationY*abs(sin(angleGarvity))
              # update Z 
              self.legRR.endEffector.Z += deviationZ*abs(cos(angleGarvity))
              self.legRL.endEffector.Z += deviationZ*abs(cos(angleGarvity))
              self.legFR.endEffector.Z += deviationZ*abs(cos(angleGarvity))
              self.legFL.endEffector.Z += deviationZ*abs(cos(angleGarvity))
              
              self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
              self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
          else:
            if self.idxRR == 8 and self.idxFR == 2:
              for i in range(0, 70):
                # update Y
                self.legRR.endEffector.Y += deviationY*abs(cos(angleGarvity))
                self.legRL.endEffector.Y += deviationY*abs(cos(angleGarvity))
                self.legFR.endEffector.Y += deviationY*abs(cos(angleGarvity))
                self.legFL.endEffector.Y += deviationY*abs(cos(angleGarvity))
                
                # update Z 
                self.legRR.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                self.legRL.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                self.legFR.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                self.legFL.endEffector.Z -= deviationZ*abs(sin(angleGarvity))
                
                self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
                self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[1], self.posCurrentPointFL[1])
            else:
              if self.idxFR == 8 and self.idxRL == 2:
                for i in range(0, 70):
                  #update Y
                  self.legRR.endEffector.Y += deviationY*abs(cos(angleGarvity))
                  self.legRL.endEffector.Y += deviationY*abs(cos(angleGarvity))
                  self.legFR.endEffector.Y += deviationY*abs(cos(angleGarvity))
                  self.legFL.endEffector.Y += deviationY*abs(cos(angleGarvity))
                  
                  # update Z 
                  self.legRR.endEffector.Z += deviationZ*abs(sin(angleGarvity))
                  self.legRL.endEffector.Z += deviationZ*abs(sin(angleGarvity))
                  self.legFR.endEffector.Z += deviationZ*abs(sin(angleGarvity))
                  self.legFL.endEffector.Z += deviationZ*abs(sin(angleGarvity))
                  
                  self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
                  self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
        time.sleep(1)

        # send message to control all legs of robot (4 leg on ground)
        self.idxRR = 19 if (self.idxRR -1) < 1 else self.idxRR -1
        self.idxRL = 19 if (self.idxRL -1) < 1 else self.idxRL -1
        self.idxFR = 19 if (self.idxFR -1) < 1 else self.idxFR -1
        self.idxFL = 19 if (self.idxFL -1) < 1 else self.idxFL -1
        self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
        for i in range(3, -1):
          self.serviceCANRos2.send_message(self.posCurrentPointRR[i], self.posCurrentPointRL[i], self.posCurrentPointFR[i], self.posCurrentPointFL[i])
          time.sleep(0.01)
        time.sleep(1)
        # if (self.idxFL == 7 and self.idxRL == 5): #or (self.idxFL == 5 and self.idxFR == 7):
        #   for i in range(0, 60):
        #     self.legRR.endEffector.Y -= deviationY*abs(cos(self.vectorAngle))
        #     self.legRL.endEffector.Y -= deviationY*abs(cos(self.vectorAngle))
        #     self.legFR.endEffector.Y -= deviationY*abs(cos(self.vectorAngle))
        #     self.legFL.endEffector.Y -= deviationY*abs(cos(self.vectorAngle))

        #     self.legRR.endEffector.Z += deviationZ*abs(sin(self.vectorAngle))
        #     self.legRL.endEffector.Z += deviationZ*abs(sin(self.vectorAngle))
        #     self.legFR.endEffector.Z += deviationZ*abs(sin(self.vectorAngle))
        #     self.legFL.endEffector.Z += deviationZ*abs(sin(self.vectorAngle))
            
        #     self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
        #     self.serviceCANRos2.send_message(self.posCurrentPointRR, self.posCurrentPointRL, self.posCurrentPointFR, self.posCurrentPointFL)
        # else:
        #   if (self.idxFR == 7 and self.idxRR== 5) or (self.idxRL == 5 and self.idxRR == 7 ):
        #     for i in range(0, 60):
        #       self.legRR.endEffector.Y += deviationY*abs(cos(self.vectorAngle))
        #       self.legRL.endEffector.Y += deviationY*abs(cos(self.vectorAngle))
        #       self.legFR.endEffector.Y += deviationY*abs(cos(self.vectorAngle))
        #       self.legFL.endEffector.Y += deviationY*abs(cos(self.vectorAngle))

        #       self.legRR.endEffector.Z -= deviationZ*abs(sin(self.vectorAngle))
        #       self.legRL.endEffector.Z -= deviationZ*abs(sin(self.vectorAngle))
        #       self.legFR.endEffector.Z -= deviationZ*abs(sin(self.vectorAngle))
        #       self.legFL.endEffector.Z -= deviationZ*abs(sin(self.vectorAngle))
              
        #       self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
        #       self.serviceCANRos2.send_message(self.posCurrentPointRR, self.posCurrentPointRL, self.posCurrentPointFR, self.posCurrentPointFL)
                  
        self.currentMode = modeControl.move.value

    if self.currentMode == modeControl.standNormal.value:
      self.vectorAngle = atan2(-xGamePad, yGamePad)
      self.oldAngleGamePad = self.vectorAngle

      if abs(self.vectorAngle) <= atan2(161.12, 187):
        self.idxRR = 5
        self.idxRL = 1
        self.idxFR = 7
        self.idxFL = 3
      
      else:
        if abs(self.vectorAngle) <= (pi - atan2(161.12, 187)):
          if self.vectorAngle < 0:
            self.idxRR = 7
            self.idxRL = 5
            self.idxFR = 3
            self.idxFL = 1
          else:
            self.idxRR = 7
            self.idxRL = 5
            self.idxFR = 3
            self.idxFL = 1
        else:
          self.idxRR = 5
          self.idxRL = 1
          self.idxFR = 7
          self.idxFL = 3
      
      
      self.updatePosCurrentPointAllLegs(self.vectorAngle, self.idxRR, self.idxRL, self.idxFR, self.idxFL)
      self.serviceCANRos2.send_message(self.posCurrentPointRR[0], self.posCurrentPointRL[0], self.posCurrentPointFR[0], self.posCurrentPointFL[0])
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

    # anglePitch = 20/180*pi
    # angleYaw = 10/180*pi

    # self.selfBalancingIMU(anglePitch, angleYaw)

    # self.posCurrentRR = self.legRR.getPosModeStandNormal()
    # self.posCurrentRL = self.legRL.getPosModeStandNormal()
    # self.posCurrentFR = self.legFR.getPosModeStandNormal()
    # self.posCurrentFL = self.legFL.getPosModeStandNormal()
    # print("checkRR: ", self.posCurrentRR)
    # print("checkRL: ", self.posCurrentRL)
    # print("checkFR: ", self.posCurrentFR)
    # print("checkFL: ", self.posCurrentFL)
    # self.serviceCANRos2.send_message(self.posCurrentRR, self.posCurrentRL, self.posCurrentFR, self.posCurrentFL)
    # the first mode when turning on the quadruped robot
    self.currentMode = modeControl.standNormal.value
    self.modeControlStandNormalAllLegs()
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
        # self.serviceIMURos2.destroy_node()
        self.serviceCANRos2.destroy_node()
        rclpy.shutdown()

#---------------------------------------------------------------------------------------------------------------------#



def main():
  robotDogTeam = quadrupedRobot()
  robotDogTeam.operation()
  
if __name__ == "__main__":
  main()
  