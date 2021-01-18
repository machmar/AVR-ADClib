/*
 * ADC.h
 *
 * Created: 1/15/2021 5:36:34 PM
 *  Author: Marek Mach
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <inttypes.h>
#include <stdbool.h>
#include <avr/io.h>

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

#define __ADC_SRC_TEMP 8
#define __ADC_SRC_1V1 14
#define __ADC_SRC_GND 15

#define __ADC_PRES_2 0
#define __ADC_PRES_4 2
#define __ADC_PRES_8 3
#define __ADC_PRES_16 4
#define __ADC_PRES_32 5
#define __ADC_PRES_64 6
#define __ADC_PRES_128 7

#define __ADC_REF_EXT 0
#define __ADC_REF_VCC 1
#define __ADC_REF_1V1 3

uint16_t analogRead(uint8_t pin);
void ADC_Init(uint8_t ClockPrescaler, uint8_t VoltageRefference);
void ADC_ConversionStart(uint8_t pin);
bool ADC_ConversionFinished();
uint16_t ADC_Result();

#endif /* ADC_H_ */