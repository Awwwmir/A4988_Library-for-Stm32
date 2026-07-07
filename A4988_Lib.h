#ifndef __A4988__
#define __A4988__


#include "stm32f1xx_hal.h"
#include "stdio.h"


// Change these based On your Micro Clock Setting
#define MicroClock 8000000
#define Pre_Scaller 8
#define AutoReloadRegister 1





// Change these based On your Time Congiguration
#define Timer &htim2
#define Timer_Pwm TIM2
#define Pwm_Channel TIM_CHANNEL_2




// Change these base on ypur CubeMx Configuration

#define DirPort     GPIOA
#define DirPin     GPIO_PIN_3
#define MS1_GPIO_PORT GPIOA
#define MS2_GPIO_PORT GPIOA
#define MS3_GPIO_PORT GPIOA
#define MS1_GPIO_Pin  GPIO_PIN_6
#define MS2_GPIO_Pin  GPIO_PIN_5
#define MS3_GPIO_Pin  GPIO_PIN_4




// Do Not Change this !!!!!
#define Full_Step_Mode 21
#define Half_Step_Mode 22	
#define Quarter_Step_Mode 23
#define Eighth_Step_Mode 24
#define Sixteenth_Step_Mode 25
#define ClockWise        30
#define CounterClockWise 31

extern TIM_HandleTypeDef htim2;


extern const float FullStepDegree;
extern float StepMode;
extern int pwm_counter;
extern int pwm_ex;


void RotateOneStep(void);
void ChangeStepResoloution(uint32_t stepresoloution);
void ChangeRotationDirection(uint32_t RotationDirection);
void StartRotateByRm(int Rpm);
void StopRotateByRm(void);
void StartRotateDegree(uint32_t Degree);


#endif 