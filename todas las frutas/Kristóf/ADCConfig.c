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

	//ADC configuration register 1 (ADC_CR1)
	ADCx->CR1 = 0x00;
	ADCx->CR1 |= 1 << 0;
	ADCx->CR1 &= ~(1 << 6);
	ADCx->CR1 |= 1 << 5;
	ADCx->CR1 &= ~(1 << 2);

	//ADC configuration register 2 (ADC_CR2)
	ADCx->CR2 |= 1 << 0;
	ADCx->CR2 &= ~(1 << 1);
	ADCx->CR2 |= 1 << 2;

	//ADC configuration register 3 (ADC_CR3)
	ADCx->CR3 = 0x1F;
	ADCx->CR3 &= ~(1 << 0);
	ADCx->CR3 &= ~(1 << 3);
	ADCx->CR3 &= ~(1 << 4);

	//ADC channel sequence 1 register (ADC_SQR1)
	ADCx->SQR[0] = 0x00;
	ADCx->SQR[0] |= 1 << 7;

	//ADC channel sequence register 2 (ADC_SQR2)
	ADCx->SQR[1] = 0x00;
	
	//ADC channel sequence register 3 (ADC_SQR3)
	ADCx->SQR[2] = 0x00;

	//ADC channel sequence register 4 (ADC_SQR4)
	ADCx->SQR[3] = 0x00;
	ADCx->SQR[3] |= 1 << 6;

	//ADC trigger disable 1 (ADC_TRIGR1)
	ADCx->TRIGR[0] = 0x00;
	ADCx->TRIGR[0] |= 1 << 0;
	ADCx->TRIGR[0] |= 1 << 1;
	ADCx->TRIGR[0] |= 1 << 2;
	ADCx->TRIGR[0] |= 1 << 3;

	//ADC trigger disable 2 (ADC_TRIGR2)
	ADCx->TRIGR[1] = 0xFF;

	//ADC trigger disable 3 (ADC_TRIGR3)
	ADCx->TRIGR[2] = 0xFF;

	//ADC trigger disable 4 (ADC_TRIGR4)
	ADCx->TRIGR[3] = 0xFF;
	ADCx->TRIGR[3] &= ~(1 << 6);

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
	ADCx->CR1 |= 1 << 1;

	/* start the conversion */
	ADC_Start(ADCx);

	/* read the ADC results, convert it to float32 and voltage, check the bound and provide availability qualifier on the signal */

	//MS bits
	uint8 ms = ADCx->DRH;
	//LS bits
	uint8 ls = ADCx->DRL;

	//to float32
	signal.value = ls;
	if (((ms >> 1) & 0x01))
		signal.value = signal.value + 512;
	if ((ms & 0x01))
		signal.value = signal.value + 256;

	//to voltage
	signal.value = signal.value / 1023 * 3.6;

	//availability
	if (signal.value < ADC_THRESHOLD_VALUE)
		signal.available = TRUE;
	if (signal.value >= ADC_THRESHOLD_VALUE)
	{
		signal.available = FALSE;
		signal.value = ADC_THRESHOLD_VALUE;
	}
		
	/* provide output */
	ProvideMeasuredSignal(signal);

}
