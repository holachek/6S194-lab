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
- [PSoC CY8CKIT-042-BLE Pioneer Kit](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-ble-bluetooth-low-energy-ble-pioneer-kit)
- [Adafruit INA219 Breakout Board](https://www.adafruit.com/product/904)
- 3x [Adafruit 0.96" OLED Display Breakout Board](https://www.adafruit.com/products/684)
- Other [OLED Displays](https://www.adafruit.com/products/1431) for comparison

### Software
- [PSoC Creator 4.0](http://www.cypress.com/products/psoc-creator-integrated-design-environment-ide) on Windows 10

### Acknowledgements
Thank you to [Dr. Phillip Stanley-Marbell](http://www.phillipstanleymarbell.org/) for idea/debugging/analysis help and [Adafruit](https://github.com/adafruit) for amazing firmware libraries.
