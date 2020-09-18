#ifndef COMPONENTTEST
#include <stdio.h> 
#include <stdlib.h> 
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef float float32;

int size = sizeof(uint32) + sizeof(float32);

typedef struct
{
    uint32  errorCode;
    float32 temperature;
} dtErrorMessage;

typedef enum
{
    FAN_OFF,
    FAN_ON
} dtFanState;
#define ERROR_CODE_OVER_TEMP    ((uint32)1u)
#define ERROR_CODE_UNDER_TEMP   ((uint32)2u)

extern float32 GetTemperature(void);
extern void    SetState(dtFanState fanState);
extern void    SendErrorReport(dtErrorMessage* errorMsg);
#endif /* !COMPONENTTEST */

/* Please add your own additions here! */

#define OVER_TEMPERATURE 160
#define UNDER_TEMPERATURE -20
#define TEMPERATURE_UPPERBOUND 25
#define HYSTERESIS 2

int temperatureLowerBound = TEMPERATURE_UPPERBOUND - HYSTERESIS;
int temperatureUpperBound = TEMPERATURE_UPPERBOUND;
dtFanState fanState = FAN_ON;

void FanControl(void){
    float actualTemperature = GetTemperature();

    if(actualTemperature > OVER_TEMPERATURE){
        dtErrorMessage overTemperatureError;
        overTemperatureError.errorCode = ERROR_CODE_OVER_TEMP;
        overTemperatureError.temperature = actualTemperature; 
        SendErrorReport(&overTemperatureError);
    }else if(actualTemperature < UNDER_TEMPERATURE){
        dtErrorMessage underTemperatureError;
        underTemperatureError.errorCode = ERROR_CODE_UNDER_TEMP;
        underTemperatureError.temperature = actualTemperature; 
        SendErrorReport(&underTemperatureError);
    }

    if(actualTemperature > temperatureUpperBound){
        fanState = FAN_ON;
    }

    if(actualTemperature < temperatureLowerBound){
        fanState = FAN_OFF;
    }

    SetState(fanState);

}
