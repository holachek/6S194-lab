# 6S194-lab
OLED color vs power characterization tools for Cypress PSoc 4.

### Overview
This project aims to understand how displaying different colors on an OLED display changes power consumed. Put another way, how do OLED displays deviate from non-ideal linear behavior? For this project I used a Cypress PSoC eval board with an INA219 voltage/current monitor and collection of Adafruit OLED displays on breakout boards.

Here are some preliminary results:

![TestCycle Demo](Analysis/TestCycleDemo.gif)
<img src="Analysis/TestCycleResults.png" alt="TestCycle Results" width="275">

### Project Motivation
Many wearable devices today have a large screen, but are fundamentally limited in maximum energy storage by technology/size of the battery. This project was a chance to understand a bit more about energy-efficient optimizations one could make to the output of a display, to achieve better system efficiency while minimizing changes to user experience.


### Hardware
- PSoC CY8CKIT-042-BLE Pioneer Kit
- Adafruit INA219 Breakout Board
- Adafruit 0.96", 1.27", 1.5" OLED Display Breakout Board

### Software
- PSoC Creator 4.0
