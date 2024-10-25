# * File: quadrupedRobot.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 17, 2024
# * Last Modified: October 17, 2024
# * Description: the program to control all operations of robot
# * Status: developing (Done, brainStorm, developing):


from controller.kinematicRobot import coordinatePoint, kinematicEachLeg
from controller.convertGlobal2LocalCoordinate import leg
import sys
sys.path.append("../../can_node/can_node")
from can_node.canController import CanNode
from custom_interfaces.srv import GamepadSrv

import time
from math import pi, atan2

# for gamepad
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
import subprocess
import time
from custom_interfaces.msg import PublishMessage


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

def main():
  # angleVector = atan2(-x, y)   # updated from the gamePad
  # robotDogTeam = quadrupedRobot()
    
  # robotDogTeam.updateTrajectoryAllLegs(angleVector)
  # trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL = robotDogTeam.getTrajectory()
  # print("----------------TRAJECTORY-----------------")
  # for i in range(len(trajectoryRR)):
  #   print("-------------point", i+ 1, "------------------")
  #   print("RR:", trajectoryRR[i])
  #   # print("RL:", trajectoryRL[i])
  #   # print("FR:", trajectoryFR[i])
  #   # print("FL:", trajectoryFL[i])
  # print("#############################################")

    rclpy.init()
    addition_client= AdditionClientAsync()
    Publish_communication = PublishCommunication()
    
    while True:
      key = input("Enter key")
      if key == 'a':
        response = addition_client.get_position()
        angleVector = atan2(-response.position[0], response.position[1])   # updated from the gamePad
        robotDogTeam = quadrupedRobot()
          
        robotDogTeam.updateTrajectoryAllLegs(angleVector)
        trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL = robotDogTeam.getTrajectory()

        Publish_communication.send_message(trajectoryRR[0], trajectoryRL[0], trajectoryFR[0], trajectoryFL[0])

        print("----------------TRAJECTORY-----------------")
        for i in range(len(trajectoryFL)):
          print("-------------point", i+ 1, "------------------")
          print("FL:", trajectoryFL[i])
          # print("RL:", trajectoryRL[i])
          # print("FR:", trajectoryFR[i])
          # print("FL:", trajectoryFL[i])
        print("#############################################")
      elif key == 'q':
         break
      
    addition_client.destroy_node()
    Publish_communication.destroy_node()
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
  