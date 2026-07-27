#include "A4988_lib.h"
#include "LCD1602.h"


int pwm_counter=0;
int pwm_ex=0;
const float FullStepDegree=1.8;
float StepMode=FullStepDegree;
  
	
	
	






void ChangeStepResolution(StepResolution_t stepResolution)
	
{
	
	switch(stepResolution)
	{
		
		case STEP_FULL:
			
		
		StepMode=FullStepDegree/1;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_RESET);
	
		
	
	break;
		
				case STEP_HALF:
			
		
		StepMode=FullStepDegree/2;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_RESET);
	
		
	
	break;
				
				
						case STEP_QUARTER:
			
		
		StepMode=FullStepDegree/4;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_RESET);
	
		
	
	break;
						
						
								case STEP_EIGHTH:
			
		
		StepMode=FullStepDegree/8;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_SET);
	
		
	
	break;
								
								
										case STEP_SIXTEENTH:
			
		
		StepMode=FullStepDegree/16;
										
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_SET);
	
		
	
	break;
										
										
										

		
	
	
}
	
}







void ChangeRotationDirection(RotationDirection_t RotationDirection)
{
	 switch(RotationDirection)
	 {
		 case ClockWise_Rotate:
		 
	HAL_GPIO_WritePin(DirPort,DirPin,GPIO_PIN_SET);
		 
		 break;
		 
		 case CounterClockWise_Rotate:
		 
	HAL_GPIO_WritePin(DirPort,DirPin,GPIO_PIN_RESET);
		 
		 break;
	
	 }
 }

 
 
 
	void StartRotateByRm(int Rpm)
	{

		char test[100];
		int DegreesInMinute=Rpm*360;
		int DegreesInSecond=DegreesInMinute/60;
		int Steps=DegreesInSecond/StepMode;
		float period=1.0/Steps;

		
		
		float ArrPreScaller=(1.0/(MicroClock/Pre_Scaller));
		
		
		int ARR=period/ArrPreScaller;
		
LCD_Clear();
	sprintf(test,"%d",ARR);
	LCD_Puts(0,0,test);
	HAL_Delay(2000);
	

		
	Timer_Pwm->ARR=ARR;
		
	__HAL_TIM_SetCompare(Timer,Pwm_Channel,ARR/2);
		HAL_TIM_PWM_Start(Timer,Pwm_Channel);
			

}
	




void StopRotateByRm(void)
{
	

	HAL_TIM_PWM_Stop(Timer,Pwm_Channel);

		
}





void StartRotateDegree(uint32_t Degree)
{
	
	pwm_ex=Degree/StepMode;
	
//	char test[200];
//	LCD_Clear();
//	sprintf(test,"%d",pwm_ex);
//	LCD_Puts(0,0,test);
//	HAL_Delay(2000);
	
	

	 
	
	
		Timer_Pwm->ARR=65000;
		
	__HAL_TIM_SetCompare(Timer,Pwm_Channel,32000);
	__HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);
	HAL_TIM_PWM_Start(Timer,Pwm_Channel);
	
	

}
	
	
	void RotateOneStep(void)
{
	
	pwm_ex=1;
	__HAL_TIM_ENABLE_IT(Timer, TIM_IT_UPDATE);
	HAL_TIM_PWM_Start(Timer,Pwm_Channel);
	

}

