%%%
# RobotArm

# Arduino

The Arduino will be the core of the system, it will be the only module that needs to connect to the with the Bluetooth and move the servos in accordance to the desired. It will ensure a good connection between Bluetooth and Arduino and control the servos according to the received Bluetooth messages.

The Arduino will control, at least, 3 servo motors (one for the base, one for the arm and another for the hand) and the Bluetooth module. Each servo motor has 3 connections (power, ground and signal), the servos are good for this project because they allow to be precisely controlled.
The Bluetooth module we used was the HC-05, it's easily installed and configured and allow us to have a good Android-Arduino communication.

<img src="https://github.com/RCarapinha/RobotArm/blob/master/Images/Arduino.png" width="500">

This circuit will power up the servos and the Bluetooth module and control all the signals that will be needed to control the arm. We only need to be careful to not overload the Arduino because of the maximum output currents.

# Android

The Android application was written in MIT App Inventor, with the help of few extra libraries, that will manage all the communication between the Arduino and Android.

The Android goal is to send signals to the Bluetooth module to control the arm. We will create/design an application with a simple and intuitive interface to connect to the Bluetooth and to control the arm.

<img src="https://github.com/RCarapinha/RobotArm/blob/master/Images/Android.png" width="500">
%%%
