# Installation
## Particle device
In a new project add the neopixel library then paste the .ino code, change to match pin and LED strip connected

## Control webpage
On line 64 enter your Access Token  
Starting on line 69 enter the room names and the Device IDs  
**This information allows complete control of your Particle device, keep this webpage private**


# Documentation
## device
exposes a particle varible and function  
The variable is json and contains power, the hue slider value, and brightness slider value.   
The function accepts a string in the format power_24bitColor_hueSlider_brightnessSlider example 1_23563_663_234

power value: binary  
24-bit color: 0 to 16777216  
hue value: 0 to 1573 made sense at the time  
brightness value: -255 to 255  

## webpage
starts with device control disabled, as devices respond it updates their status and they are controllable
for each device there is: a power indicator, the chosen light color, room name, a hue slider, and a brightness slider
