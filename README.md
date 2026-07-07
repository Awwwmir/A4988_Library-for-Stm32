Hello !
This is A libraru to use A4988 Stepper Motor Driver For Stm32.
To Use it :


1-Configure Your Cube_Mx Setting to have a timer.



2-in main.c add this as a intruppt 


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	

	
	pwm_counter++;
	
	
	
	if(pwm_counter==pwm_ex)
	{
		HAL_TIM_PWM_Stop(Timer,Pwm_Channel);
		__HAL_TIM_DISABLE_IT(Timer, TIM_IT_UPDATE);
	pwm_counter=0;
		
	}



}


3- Change A4988_LIB.h Configuration 

4- Start !

Hope u Enjoy it my friens...
