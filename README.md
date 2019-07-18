# 8bitdo-n64-oem-joystick
Use original N64 joystick with 8bitdo N64 retro controller circuit board and turn an original N64 controller into a bluetooth gamepad.

I wanted to play N64 emulator with a wireless N64 controller. I bought 8bitdo's N64 bluetooth replica and although it is quite good, having spent my childhood playing N64 I can tell it doesn't feel the same. Thanks to [this guy](https://www.instructables.com/id/8bitdo-OEM-Wireless-N64-Controller/) I learned you can fit 8bitdo's controller board into an original N64 controller's case, and use original buttons. That was an improvement but I really wanted to have 100% original N64 experience. So I built this in order to replace 8bitdo's joystick based on two 10k potentiometers by the original N64 joystick, and this is the process:

N64 joystick signals come from two linear encoders. Each axis has to signals, I and Q. Long story short, whenever I is high you should read Q, if Q is the same level as I it means the joystick is going in one direction. If the voltage level is the opposite, the joystick is moving in the other direction. To know what direction corresponds each case you just have to find out testing. I only triggers if the joystick is moving.

This is how you would see that signal in an oscilloscope:

<img src="images/signal.png?raw=true" width="350">

8bitdo's board expect a simple voltage level between 0 and 3.3V for each axis, this voltage level is controlled by a 10K potentiometer. In order to convert one signal to another I used a PIC 12F675 that receives I and Q signals from the original N64 joystick to know what is happening and control a X9C103S digital potentiometer. The X9C103S output is connected to 8bitdo's joystick input pad.

<img src="images/diagram.png?raw=true">

These are pictures of a board for one axis converter, two of these are needed:

<img src="images/1.jpeg?raw=true" width="500">
<img src="images/2.jpeg?raw=true" width="500">

I decided to put them one of each of the sides of the controller, they fit very well:

<img src="images/3.jpg?raw=true" width="500">
<img src="images/4.jpg?raw=true" width="500">

I had to adapt the case a little bit to fit but nothing too hard, and this is the final result:

<img src="images/5.jpg?raw=true" width="500">
<img src="images/6.jpg?raw=true" width="500">
