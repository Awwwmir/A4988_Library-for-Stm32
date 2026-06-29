#include "A4988_lib.h"


void ChangeStepResoloution(uint32_t stepresoloution)
	
{
	
	switch(stepresoloution)
	{
		
		case 21:
			
		
		StepMode=FullStepDegree/1;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_RESET);
	
		
	
	break;
		
				case 22:
			
		
		StepMode=FullStepDegree/2;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_RESET);
	
		
	
	break;
				
				
						case 23:
			
		
		StepMode=FullStepDegree/4;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_RESET);
	
		
	
	break;
						
						
								case 24:
			
		
		StepMode=FullStepDegree/8;
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_SET);
	
		
	
	break;
								
								
										case 25:
			
		
		StepMode=FullStepDegree/16;
										
			
		HAL_GPIO_WritePin(MS1_GPIO_PORT,MS1_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS2_GPIO_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(MS2_GPIO_PORT,MS3_GPIO_Pin,GPIO_PIN_SET);
	
		
	
	break;
										
										
										

		
	
	
}
	
}







void ChangeRotationDirection(uint32_t RotationDirection)
{
	 switch(RotationDirection)
	 {
		 case 30:
		 
	HAL_GPIO_WritePin(DirPort,DirPin,GPIO_PIN_SET);
		 
		 break;
		 
		 case 31:
		 
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

		
		int ARR=period/ArrPreScaller;
		

	sprintf(test,"%d",ARR);
		
	Timer_Pwm->ARR=ARR;
		
	__HAL_TIM_SetCompare(Timer,Pwm_Channel,ARR/2);
		HAL_TIM_PWM_Start(Timer,Pwm_Channel);
			

}
	




void StopRotateByRm()
{
	

	HAL_TIM_PWM_Stop(Timer,Pwm_Channel);

		
}





void StartRotateDegree(uint32_t Degree)
{
	
	Degree=Degree/StepMode;
	
	
	for(int k=0;k<Degree;k++)
	{
		
	HAL_GPIO_WritePin(GPIO_Step_Port,GPIO_Step_Pin,GPIO_PIN_SET);
  HAL_Delay(100);
	
	HAL_GPIO_WritePin(GPIO_Step_Port,GPIO_Step_Pin,GPIO_PIN_RESET);
  HAL_Delay(100);
		
	}
	
}
	
	
	

