/*
 * ADCConfig.c
 *
 *  Created on: 2019 júl. 2
 *      Author: marton.antal
 */

#include "ADCConfig_tester.h"

void ADCConfig(ADC_TypeDef* ADCx)
{
	/* set the registers to fulfill the written requirements */

	/* Initialize the ADC with the configuration defined in the struct */
	ADC_Init(ADCx);

}

/* This function is invoked periodically. Here you should start the conversion, and check the results according to the requirements.
 * You can expect that the maximum value is 3.6Volt @ 10bit
 * */
void ADC_Task(ADC_TypeDef* ADCx)
{

	dtSignal signal = {FALSE, 0.f};

	/* set ADC bit to start the conversion */

	/* start the conversion */
	ADC_Start(ADCx);

	/* read the ADC results, convert it to float32 and voltage, check the bound and provide availability qualifier on the signal */

	/* provide output */
	ProvideMeasuredSignal(signal);

}
