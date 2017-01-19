#include <stdio.h>
#include <project.h>

#include "ina219.h"
#include "ssd1331.h"
#include "ssd1351.h"

#define INA219_SHUNT_RESISTANCE 0.1

uint8_t I2CM_ReadBuf[100];
uint8_t I2CM_WriteBuf[100];

char output[100];

#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

// make 24-bit color into 16-bit color (5-bit r, 6-bit g, 5-bit b)
uint16_t makeColor888(uint8_t r, uint8_t g, uint8_t b)
{
    uint16_t c;
    
    c = r >> 3;
    c <<= 6;
    c |= g >> 2;
    c <<= 5;
    c |= b >> 3;

    return c;
}

// make 16-bit color into 16-bit color
uint16_t makeColor565(uint8_t r, uint8_t g, uint8_t b)
{
    uint16_t c;
    
    c = r;
    c <<= 6;
    c |= g;
    c <<= 5;
    c |= b;
    
    return c;
}

void drawRectangle(uint16_t fillColor){
 
    // Draw rectangle
    SPIM_WriteTxData(0x26); // enable fill
    SPIM_WriteTxData(0x01);
    
    SPIM_WriteTxData(0x22); // draw rect command
    SPIM_WriteTxData(0x00); // column address of start
    SPIM_WriteTxData(0x00); // row address of start
    SPIM_WriteTxData(0x5F); // column address of end
    SPIM_WriteTxData(0x3F); // row address of end
    SPIM_WriteTxData(0x00); // line colors
    SPIM_WriteTxData(0x00);
    SPIM_WriteTxData(0x00);
    
    // fill colors by calculating R, G, B from 16-bit number
    SPIM_WriteTxData((uint8_t)((fillColor >> 11) << 1)); // red = [5:1]
    SPIM_WriteTxData((uint8_t)((fillColor >> 5) & 0x3F)); // green = [5:0]
    SPIM_WriteTxData((uint8_t)((fillColor << 1) & 0x3F)); // blue = [5:1]
    
    CyDelay(10);
    
}

// See color wheel diagram
// http://academe.co.uk/wp-content/uploads/2012/04/451px-HSV-RGB-comparison.svg_.png
uint16_t Wheel(uint8_t WheelPos) {
  if(WheelPos < 85) {
   return makeColor888(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return makeColor888(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return makeColor888(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


void InitSSD1331OLED() {
    OLED_DATA_CMD_CTRL_Write(0);
    SPIM_WriteTxData(SSD1331_CMD_DISPLAYOFF);
    SPIM_WriteTxData(SSD1331_CMD_SETREMAP);
    SPIM_WriteTxData(0x72); // RGB color mode
    SPIM_WriteTxData(SSD1331_CMD_STARTLINE);
    SPIM_WriteTxData(0x00);
    SPIM_WriteTxData(SSD1331_CMD_DISPLAYOFFSET);
    SPIM_WriteTxData(0x00);
    SPIM_WriteTxData(SSD1331_CMD_NORMALDISPLAY);
    SPIM_WriteTxData(SSD1331_CMD_SETMULTIPLEX);
    SPIM_WriteTxData(0x3F); // 1/64 duty cycle
    SPIM_WriteTxData(SSD1331_CMD_POWERMODE);
    SPIM_WriteTxData(0x0B);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGE);
    SPIM_WriteTxData(0x31);
    SPIM_WriteTxData(SSD1331_CMD_CLOCKDIV);
    SPIM_WriteTxData(0xF0);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGEA);
    SPIM_WriteTxData(0x64);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGEB);
    SPIM_WriteTxData(0x78);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGEA);
    SPIM_WriteTxData(0x64);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGELEVEL);
    SPIM_WriteTxData(0x3A);
    SPIM_WriteTxData(SSD1331_CMD_VCOMH);
    SPIM_WriteTxData(0x3E);
    SPIM_WriteTxData(SSD1331_CMD_MASTERCURRENT);
    SPIM_WriteTxData(0x06);
    SPIM_WriteTxData(SSD1331_CMD_CONTRASTA);
    SPIM_WriteTxData(0xFF); // default 0x91
    SPIM_WriteTxData(SSD1331_CMD_CONTRASTB);
    SPIM_WriteTxData(0xFF); // default x050
    SPIM_WriteTxData(SSD1331_CMD_CONTRASTC);
    SPIM_WriteTxData(0xFF); // default 0x7D
    SPIM_WriteTxData(SSD1331_CMD_DISPLAYON);   
}

void InitSSD1351OLED() {
    OLED_DATA_CMD_CTRL_Write(0);
    SPIM_WriteTxData(SSD1331_CMD_DISPLAYOFF);
    SPIM_WriteTxData(SSD1331_CMD_SETREMAP);
    SPIM_WriteTxData(0x72); // RGB color mode
    SPIM_WriteTxData(SSD1331_CMD_STARTLINE);
    SPIM_WriteTxData(0x00);
    SPIM_WriteTxData(SSD1331_CMD_DISPLAYOFFSET);
    SPIM_WriteTxData(0x00);
    SPIM_WriteTxData(SSD1331_CMD_NORMALDISPLAY);
    SPIM_WriteTxData(SSD1331_CMD_SETMULTIPLEX);
    SPIM_WriteTxData(0x3F); // 1/64 duty cycle
    SPIM_WriteTxData(SSD1331_CMD_POWERMODE);
    SPIM_WriteTxData(0x0B);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGE);
    SPIM_WriteTxData(0x31);
    SPIM_WriteTxData(SSD1331_CMD_CLOCKDIV);
    SPIM_WriteTxData(0xF0);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGEA);
    SPIM_WriteTxData(0x64);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGEB);
    SPIM_WriteTxData(0x78);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGEA);
    SPIM_WriteTxData(0x64);
    SPIM_WriteTxData(SSD1331_CMD_PRECHARGELEVEL);
    SPIM_WriteTxData(0x3A);
    SPIM_WriteTxData(SSD1331_CMD_VCOMH);
    SPIM_WriteTxData(0x3E);
    SPIM_WriteTxData(SSD1331_CMD_MASTERCURRENT);
    SPIM_WriteTxData(0x06);
    SPIM_WriteTxData(SSD1331_CMD_CONTRASTA);
    SPIM_WriteTxData(0x91); // default 0x91
    SPIM_WriteTxData(SSD1331_CMD_CONTRASTB);
    SPIM_WriteTxData(0x50); // default x050
    SPIM_WriteTxData(SSD1331_CMD_CONTRASTC);
    SPIM_WriteTxData(0x7D); // default 0x7D
    SPIM_WriteTxData(SSD1331_CMD_DISPLAYON);   
}

int main()
{
    I2CM_Start();
    SPIM_Start();
    
    
    UART_Start();
    UART_UartPutString( "\n\nINA219 I2C + SSD1331 SPI Demo\r\n" );
    
    CyGlobalIntEnable;
    
    
    // Begin communication with SSD1331 display
    
    OLED_RST_Write(0);  // reset OLED
    CyDelay(10);
    OLED_RST_Write(1);
    
    // Init sequence
    OLED_DATA_CMD_CTRL_Write(0);
    
    OLED_CS_SEL_Write(0); // control the first oled
    InitSSD1331OLED();
    
    CyDelay(10);
    
    OLED_CS_SEL_Write(1);
    InitSSD1351OLED();
    
    OLED_CS_SEL_Write(0);
    
    // Start by sending config to INA219
    uint16_t config = INA219_REG_CONFIG_BRNG_16V |
                      INA219_REG_CONFIG_PG_4 |
                      INA219_REG_CONFIG_BADC_12BIT |
                      INA219_REG_CONFIG_SADC_12BIT_32S |
                      INA219_REG_CONFIG_MODE_SVOLT_BVOLT_CONT;
    
    I2CM_I2CMasterSendStart(INA219_ADDRESS, I2CM_I2C_WRITE_XFER_MODE);
    I2CM_I2CMasterWriteByte(INA219_REG_CONFIG);
    I2CM_I2CMasterWriteByte((config >> 8) & 0xFF); // upper 8 bits
    I2CM_I2CMasterWriteByte(config & 0xFF); // lower 8 bits
    I2CM_I2CMasterSendStop();
    CyDelay(10);
    
    sprintf(output, "Configuration set to: %04X\r\n\n", config);
    UART_UartPutString(output);
    
    I2CM_I2CMasterReadBuf(INA219_ADDRESS, I2CM_ReadBuf, 2, I2CM_I2C_MODE_COMPLETE_XFER);
    CyDelay(10);
    
    uint16_t config_readback = (I2CM_ReadBuf[0] << 8) + (I2CM_ReadBuf[1]);
    
    sprintf(output, "Configuration I2C readback: %04X\r\n\n", config_readback);
    UART_UartPutString(output);
    
    I2CM_WriteBuf[0] = INA219_REG_SHUNTVOLTAGE;
    
    // Set read location
    I2CM_I2CMasterWriteBuf(INA219_ADDRESS, I2CM_WriteBuf, 1, I2CM_I2C_MODE_COMPLETE_XFER);
    CyDelay(10);
    
    while(I2CM_I2CMasterStatus() == I2CM_I2C_MSTAT_XFER_INP);
        
    int r, g, b;
    uint8_t red32, green64, blue32;
    uint16_t current_color;
    
    for(;;)
    {
        
        // 16-bit color read
        for (r=0; r<3; r++){
            for (g=0; g<32; g++){
                // for (b=0; b<32; b++){
            
                    if(r==0){
                        current_color = makeColor565(g, 0, 0);
                    } else if (r==1){
                        current_color = makeColor565(0, g*2, 0);
                    } else if (r==2){
                        current_color = makeColor565(0, 0, g);   
                    }
                    
                    // uint16_t current_color = makeColor565(r, g, b);
                    drawRectangle(current_color);  
                    CyDelay(35);
                
                    // Read current register location
                    I2CM_I2CMasterReadBuf(INA219_ADDRESS, I2CM_ReadBuf, 2, I2CM_I2C_MODE_REPEAT_START);
                    while(I2CM_I2CMasterStatus() == I2CM_I2C_MSTAT_XFER_INP);
                    
                    uint16_t shunt_reg_val = (I2CM_ReadBuf[0] << 8) + (I2CM_ReadBuf[1]);
                    double shunt_voltage = (double)shunt_reg_val / 100.0;
                    double display_current = (double)shunt_voltage / INA219_SHUNT_RESISTANCE;
                    
                    /*
                    sprintf(output, "I2C Read Shunt Reg Value: %04X\r\n", shunt_reg_val);
                    UART_UartPutString(output);
                    */
                    
                    // sprintf(output, "Wheel Position: %i\t\t", j);
                    
                    // MegunoLink XY plotting syntax: {XYPLOT|DATA|Series|yourXdata|yourYdata}
                    // sprintf(output, "{XYPLOT|DATA|Series|%i", current_color);
                    // sprintf(output, "{XYPLOT|DATA|Series|%i", g);
                    // UART_UartPutString(output);
                    
                    // sprintf(output, "Shunt Voltage: %.2f mV\r\n\n", shunt_voltage);
                    sprintf(output, "%.3f, ", display_current);
                    UART_UartPutString(output);
                    
                    if(g == 0){
                     sprintf(output, "\r\n\n\n%i\n", r);
                     UART_UartPutString(output);
                    }
                    
                    red32 = ((current_color >> 11)); // red = [4:0]
                    green64 = ((current_color >> 5) & 0x3F); // green = [5:0]
                    blue32 = ((current_color) & 0x1F); // blue = [4:0]
                    
                    // print out r, g, b values
                    //sprintf(output, "[r:%i, g:%i, b:%i]\r\n", red32, green64, blue32);
                    //UART_UartPutString(output);
                    
                // } // end b loop
            } // end g loop
        } // end r loop
        
    }
}






/* [] END OF FILE */
