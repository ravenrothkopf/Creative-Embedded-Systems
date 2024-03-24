# Module 2 - Interactive Devices
The goal of this project was to make an interactive art installation involving a TTGO T-Display and several input interfaces. I chose to revamp an old video game I made at the end of high school with a responsive game controller. My inspiration was restoring a game I made 5 years and adding to my first attempt at a programming project with the knowledge I have gained since going through college as a computer science major. My system allows the player to control an 8-bit super mario character in a Pacman-style game. The player must collect all of the coins on the screen while trying to not get hit by the Goombas (ghosts) and collect 1-UPS distributed across the map to help with this mission. Thee joystick controller button is used to click through the navigational and instructional screens of the game. Three LED lights on the controller respond to different actions during gameplay. The red LED light turns on every time the player gets hit by a Goomba, the yellow LED light every time the player collects a coin, and the green LED light every time the player gets a 1-UP.

## Materials List
### Hardware
- ESP32 TTGO T-display
- USB-C
- Mac (version 13.X)
- Solderless Breadboard 350 Tie-Points 1 Distribution Strip
- Joystick
- 1 each of red, yellow, and green LED lights
- 3 220 Ω resistors
- 4 female to male wires
- 4 male to male wires
### Software
-  Pygame (version 2.5.X)
-  Ultimaker Cura (Version 5.6.X)
### Enclosure
- Ultimaker 3D printer
- PLA filament
- `enclosure.stl` enclosure model
- 4 3mm screws
- Scotch tape
- Hot glue
- Ribbon (or any long strip of sturdy material)

## Getting started: Software
1. Download Arduino Legacy IDE (1.8.X): https://www.arduino.cc/en/software
2. Download driver to get port /dev/cu.wchusbserialXXXXXXXX: https://www.wch.cn/downloads/CH34XSER_MAC_ZIP.html
3. Download Pygame
4. Download Ultimaker Cura and connect to your Ultimaker printer (can use any 3D printing software/printer that takes `.stl` files)
## Getting started: Hardware
- Attach TTGO and joystick to the breadboard
- Make the following wire connections for the joystick: bottom left TTGO GND -> negative side of left distribution strip, Joystick GND -> second-to-bottom left ground on the TTGO, Joystick 5V -> bottom left 3V, Joystick VRy -> TTGO 15, Joystick VRx -> TTGO 12, Joystick SW -> TTGO 13
- Make the following wire connections for the LED lights: Red, yellow, and green LED light to top left of breadboard, cathode in the negative side of the distribution strip, anode... Red LED -> resistor -> TTGO 22, Yellow LED -> resistor -> TTGO 21, Green LED -> resistor -> TTGO 17
- Plug in USB-C into computer and the ESP
## Download and Upload Code
- To Download the code: ```git clone https://github.com/ravenrothkopf/Creative-Embedded-Systems/tree/main/Module%202/```
- Open the file `mario_pacman.ino` in the Arduino IDE and select Upload
- Open the `game` folder in Pygame IDE and run Final.py
- Interact with the joystick and see the LED lights change!

