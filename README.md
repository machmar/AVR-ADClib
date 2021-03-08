# AVR-ADClib
Just something I quickly wrote to make the use of ADCs as simply and quickly as possible without compromising any features.  
There are no delays or anything used - only busy flags.  
This library has been tested on the AtMega 328p and it works only with the AtMega series.

## Usage:
1.  **SLOW**  
    Use the `analogRead(pin)` function to quickly get the analog value.  

2.  **FAST**  
    Initialize the ADC with `ADC_Init(ClockPrescaler, VoltageRefference)`.  
    Start the conversion with `ADC_ConversionStart(pin)`.  
    Check the state of the conversion with `ADC_ConversionFinished()`.  
    Get the final value with `ADC_Result()`.  
    
I have also included many useful Macros:  
 
For *Input* selection  
 
    A0 0  inputs just like when using arduino
    A1 1
    A2 2
    A3 3
    A4 4
    A5 5
    A6 6
    A7 7
    __ADC_SRC_TEMP 8  buil-in temperature sensor
    __ADC_SRC_1V1 14  built-in band-gap refference generator
    __ADC_SRC_GND 15  just ground connection

For *Clock Prescalers*

    __ADC_PRES_2 0
    __ADC_PRES_4 2
    __ADC_PRES_8 3
    __ADC_PRES_16 4
    __ADC_PRES_32 5
    __ADC_PRES_64 6
    __ADC_PRES_128 7

For *Voltage Refference* selection

    __ADC_REF_EXT 0
    __ADC_REF_VCC 1
    __ADC_REF_1V1 3
