/* ========================================
    SSD1351 OLED Display Library for PSoC
    
    Modified from Adafruit-SSD1351-library
    https://github.com/adafruit/Adafruit-SSD1351-library
* ========================================
*/

#define SSD1351HRES 128
#define SSD1351VRES 128

/*=========================================================================

    COMMANDS

    -----------------------------------------------------------------------*/
    #define SSD1351_CMD_SETCOLUMN       0x15
    #define SSD1351_CMD_SETROW          0x75
    #define SSD1351_CMD_WRITERAM        0x5C
    #define SSD1351_CMD_READRAM         0x5D
    #define SSD1351_CMD_SETREMAP        0xA0
    #define SSD1351_CMD_STARTLINE       0xA1
    #define SSD1351_CMD_DISPLAYOFFSET   0xA2
    #define SSD1351_CMD_DISPLAYALLOFF   0xA4
    #define SSD1351_CMD_DISPLAYALLON    0xA5
    #define SSD1351_CMD_NORMALDISPLAY   0xA6
    #define SSD1351_CMD_INVERTDISPLAY   0xA7
    #define SSD1351_CMD_FUNCTIONSELECT  0xAB
    #define SSD1351_CMD_DISPLAYOFF      0xAE
    #define SSD1351_CMD_DISPLAYON       0xAF
    #define SSD1351_CMD_PRECHARGE       0xB1
    #define SSD1351_CMD_DISPLAYENHANCE  0xB2
    #define SSD1351_CMD_CLOCKDIV        0xB3
    #define SSD1351_CMD_SETVSL          0xB4
    #define SSD1351_CMD_SETGPIO         0xB5
    #define SSD1351_CMD_PRECHARGE2      0xB6
    #define SSD1351_CMD_SETGRAY         0xB8
    #define SSD1351_CMD_USELUT          0xB9
    #define SSD1351_CMD_PRECHARGELEVEL  0xBB
    #define SSD1351_CMD_VCOMH           0xBE
    #define SSD1351_CMD_CONTRASTABC     0xC1
    #define SSD1351_CMD_CONTRASTMASTER  0xC7
    #define SSD1351_CMD_MUXRATIO        0xCA
    #define SSD1351_CMD_COMMANDLOCK     0xFD
    #define SSD1351_CMD_HORIZSCROLL     0x96
    #define SSD1351_CMD_STOPSCROLL      0x9E
    #define SSD1351_CMD_STARTSCROLL     0x9F



/* [] END OF FILE */
