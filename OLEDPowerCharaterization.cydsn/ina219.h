/* ========================================
    INA219 Voltage/Current Monitor Library for PSoC
    
    Modified from Adafruit_INA219 Library
    https://github.com/adafruit/Adafruit_INA219
* ========================================
*/

/*=========================================================================

    I2C ADDRESS

    -----------------------------------------------------------------------*/
    #define INA219_ADDRESS                      (0x40)      // Default I2C address

/*=========================================================================

    CONFIG REGISTER (R/W)

    -----------------------------------------------------------------------*/
    #define INA219_REG_CONFIG                   (0x00)

    #define INA219_REG_CONFIG_RESET             (0x8000)    // Reset all settings

    #define INA219_REG_CONFIG_BRNG_MASK         (0x2000)    // Bus voltage range mask
    #define INA219_REG_CONFIG_BRNG_16V          (0x0000)    // 0-16V full scale range
    #define INA219_REG_CONFIG_BRNG_32V          (0x2000)    // 0-32V full scale range

    #define INA219_REG_CONFIG_PG_MASK           (0x1800)    // Shunt voltage gain mask
    #define INA219_REG_CONFIG_PG_1              (0x0000)    // Gain 1, 40mV range
    #define INA219_REG_CONFIG_PG_2              (0x0800)    // Gain 2, 80mV range
    #define INA219_REG_CONFIG_PG_3              (0x1000)    // Gain 3, 160mV range
    #define INA219_REG_CONFIG_PG_4              (0x1800)    // Gain 4, 320mV range

    #define INA219_REG_CONFIG_BADC_MASK         (0x0780)    // Bus ADC resolution mask
    #define INA219_REG_CONFIG_BADC_9BIT         (0x0080)    // 9-bit resolution (0-511)
    #define INA219_REG_CONFIG_BADC_10BIT        (0x0100)    // 10-bit resolution (0-1023)
    #define INA219_REG_CONFIG_BADC_11BIT        (0x0200)    // 11-bit resolution (0-2047)
    #define INA219_REG_CONFIG_BADC_12BIT        (0x0400)    // 12-bit resolution (0-4097)

    #define INA219_REG_CONFIG_SADC_MASK         (0x0078)    // Shunt ADC resolution and avg mask
    #define INA219_REG_CONFIG_SADC_9BIT_1S      (0x0000)    // 1 x 9-bit shunt sample, 84us
    #define INA219_REG_CONFIG_SADC_10BIT_1S     (0x0008)    // 1 x 10-bit shunt sample, 148us
    #define INA219_REG_CONFIG_SADC_11BIT_1S     (0x0010)    // 1 x 11-bit shunt sample, 276us
    #define INA219_REG_CONFIG_SADC_12BIT_1S     (0x0018)    // 1 x 12-bit shunt sample, 532us
    #define INA219_REG_CONFIG_SADC_12BIT_2S     (0x0048)    // 2 x 12-bit shunt sample avgd, 1060us
    #define INA219_REG_CONFIG_SADC_12BIT_4S     (0x0050)    // 4 x 12-bit shunt sample avgd, 2130us
    #define INA219_REG_CONFIG_SADC_12BIT_8S     (0x0058)    // 8 x 12-bit shunt sample avgd, 4260us
    #define INA219_REG_CONFIG_SADC_12BIT_16S    (0x0060)    // 16 x 12-bit shunt sample avgd, 8510us
    #define INA219_REG_CONFIG_SADC_12BIT_32S    (0x0068)    // 32 x 12-bit shunt sample avgd, 17ms
    #define INA219_REG_CONFIG_SADC_12BIT_64S    (0x0070)    // 64 x 12-bit shunt sample avgd, 34ms
    #define INA219_REG_CONFIG_SADC_12BIT_128S   (0x0078)    // 128 x 12-bit shunt sample avgd, 69ms

    #define INA219_REG_CONFIG_MODE_MASK         (0x0007)    // Operating mode mask
    #define INA219_REG_CONFIG_MODE_POWERDOWN    (0x0000)
    #define INA219_REG_CONFIG_MODE_SVOLT_TGD    (0x0001)    // Shunt voltage, triggered
    #define INA219_REG_CONFIG_MODE_BVOLT_TGD    (0x0002)    // Bus voltage, triggered
    #define INA219_REG_CONFIG_MODE_SVOLT_BVOLT_TGD  (0x0003)// Shunt and bus voltage, triggered
    #define INA219_REG_CONFIG_MODE_ADCOFF       (0x0004)    // ADC off, disabled
    #define INA219_REG_CONFIG_MODE_SVOLT_CONT   (0x0005)    // Shunt voltage, continuous
    #define INA219_REG_CONFIG_MODE_BVOLT_CONT   (0x0006)    // Bus voltage, continuous
    #define INA219_REG_CONFIG_MODE_SVOLT_BVOLT_CONT (0x0007)// Shunt and bust voltage, continous

    
/*=========================================================================

    SHUNT VOLTAGE REGISTER (R)

    -----------------------------------------------------------------------*/
    #define INA219_REG_SHUNTVOLTAGE                (0x01)

/*=========================================================================*/



/*=========================================================================

    BUS VOLTAGE REGISTER (R)

    -----------------------------------------------------------------------*/
    #define INA219_REG_BUSVOLTAGE                  (0x02)

/*=========================================================================*/



/*=========================================================================

    POWER REGISTER (R)

    -----------------------------------------------------------------------*/
    #define INA219_REG_POWER                       (0x03)

/*=========================================================================*/



/*=========================================================================

    CURRENT REGISTER (R)

    -----------------------------------------------------------------------*/
    #define INA219_REG_CURRENT                     (0x04)

/*=========================================================================*/



/*=========================================================================

    CALIBRATION REGISTER (R/W)

    -----------------------------------------------------------------------*/
    #define INA219_REG_CALIBRATION                 (0x05)

/*=========================================================================*/







/* [] END OF FILE */
