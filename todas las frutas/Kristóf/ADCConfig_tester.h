/*
 * ADCConfig_tester.h
 *
 *  Created on: 2019 júl. 15
 *      Author: marton.antal
 */

#include "stdio.h"

#ifndef PARAMETERS
#define FALSE	0u
#define TRUE	1u
#define ADC_THRESHOLD_VALUE (float32)2.0f

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef float float32;

/* signal structure */
typedef struct
{
    boolean available;
    float32 value;
} dtSignal;

/* Analog to Digital Converter (ADC) peripheral */
typedef struct ADC_struct
{
  uint8   CR1;      /*!< Control register 1    */
  uint8   CR2;      /*!< Control register 2    */
  uint8   CR3;      /*!< Control register 3    */
  uint8   SR;       /*!< Status register    */
  uint8   DRH;      /*!< Data register MSB    */
  uint8   DRL;      /*!< Data register LSB    */
  uint8   HTRH;     /*!< High voltage reference register MSB    */
  uint8   HTRL;     /*!< High voltage reference register LSB    */
  uint8   LTRH;     /*!< Low voltage reference register MSB    */
  uint8   LTRL;     /*!< Low voltage reference register LSB    */
  uint8   SQR[4];   /*!< Channel select scan registers    */
  uint8   TRIGR[4]; /*!< Trigger disable  registers  */
}
ADC_TypeDef;
#endif /* !PARAMETERS */

/* The following APIs can be used */
extern void ADCConfig(ADC_TypeDef*);
void ADC_Init(ADC_TypeDef* ADCx);
void ADC_Start(ADC_TypeDef* ADCx);
extern void ADC_Task(ADC_TypeDef*);
void ProvideMeasuredSignal(dtSignal);
