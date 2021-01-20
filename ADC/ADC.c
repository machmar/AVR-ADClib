/* 
 * ADC.c
 *
 * Created: 1/16/2021 1:38:34 AM
 *  Author: Marek Mach
 */ 

#include "ADC.h"

uint16_t analogRead(uint8_t pin) {
	ADMUX = pin;				//select the pin in the analog multiplexer
	ADMUX |= (0b01 << REFS0);		//select AVcc as the reference voltage
	DIDR0 = (1 << pin);			//disable the selected pin
	
	PRR &= ~(1 << PRADC);			//disable power reduction
	ADCSRA |= (1 << ADEN);			//enable the ADC
	ADCSRA |= (0b111 << ADPS0);		//set the clock division to 125kHz
	ADCSRA |= (1 << ADSC);			//start conversion
	while (bit_is_set(ADCSRA, ADSC));	//wait for the conversion to finish
	
	DIDR0 = (0 << pin);			//enable the selected pin
	uint16_t output = ADCL | (ADCH << 8);	//make the output variable from the two registers
	return output;				//return the combined 10bit value
}

void ADC_Init(uint8_t ClockPrescaler, uint8_t VoltageRefference) {
	PRR &= ~(1 << PRADC);			//disable power reduction
	ADMUX |= (VoltageRefference << REFS0);	//select the reference voltage
	ADCSRA |= (1 << ADEN);			//enable the ADC
	ADCSRA |= (ClockPrescaler << ADPS0);	//set the clock division
}

void ADC_ConversionStart(uint8_t pin) {
	DIDR0 = (1 << pin);			//disable the selected pin
	ADMUX &= ~(0b00001111);			//clearing the ADMUX MUX part so it doesn't break refference settings
	ADMUX |= pin;				//set the ADC mux to the selected pin
	ADCSRA |= (1 << ADSC);			//start conversion
}

bool ADC_ConversionFinished() {
	return !bit_is_set(ADCSRA, ADSC);	//check if the conversion is still running
}

uint16_t ADC_Result() {
	while (bit_is_set(ADCSRA, ADSC));	//wait until the conversion is done
	DIDR0 = 255;				//enable the selected pin
	uint16_t output = ADCL | (ADCH << 8);	//make the output variable from the two registers
	return output;				//return the combined 10bit value
}
