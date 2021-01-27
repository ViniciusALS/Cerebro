# Robotic Arm Code

<p align="center">
  <img src="../.github/resources/robotic arm.jpg" height="200px"/>
</p>

The Robotic Arm code is build around an [Arduino UNO](https://store.arduino.cc/usa/arduino-uno-rev3) using the [Arduino IDE](https://www.arduino.cc/en/software).


### Getting Started

The main file for the program is the [Project.ino](Project/Project.ino) file. Because of how the Arduino IDE works, the main source code has to have the same name as the folder and all source code files must be on the root folder at the same level as the main file.


### Understanding the Robot

The robotic arm has four servo motors to control the base movement, the arm, the forearm, and the claw. Each motor is connected to a PWM output pin of the Arduino.


### Controlling the Robot

The program expects a stream of digits from the serial monitor. These digits dictate what action the robot will take. There are 4 possible actions:

0. Await - The robot remains still waiting for the next command.
1. Turn Left - The robot base rotates to the left.
2. Turn Right - The robot base rotates to the right.
3. Toggle - The robot's arm toggles in between the holding position and the released position.