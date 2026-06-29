#ifndef __A4988__
#define __A4988__


#include "stm32f1xx_hal.h"
#include "stdio.h"


const float FullStepDegree=1.8;



#define GPIO_Step_Port GPIOA
#define GPIO_Step_Pin  GPIO_PIN_11
#define DirPort     GPIOB
#define DirPin     GPIO_PIN_14
#define MS1_GPIO_PORT GPIOB
#define MS2_GPIO_PORT GPIOB
#define MS3_GPIO_PORT GPIOB
#define MS1_GPIO_Pin  GPIO_PIN_15
#define MS2_GPIO_Pin  GPIO_PIN_14
#define MS3_GPIO_Pin  GPIO_PIN_13


#define Full_Step_Mode 21
#define Half_Step_Mode 22	
#define Quarter_Step_Mode 23
#define Eighth_Step_Mode 24
#define Sixteenth_Step_Mode 25

#define Timer &htim1
#define Timer_Pwm TIM1
#define Pwm_Channel TIM_CHANNEL_1

#define ArrPreScaller      0.000001


#define ClockWise        30
#define CounterClockWise 31

extern TIM_HandleTypeDef htim1;


float StepMode=FullStepDegree;

void ChangeStepResoloution(uint32_t stepresoloution);
void ChangeRotationDirection(uint32_t RotationDirection);
void StartRotateByRm(int Rpm);
void StopRotateByRm();
void StartRotateDegree(uint32_t Degree);


#endif 