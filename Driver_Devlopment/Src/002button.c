/*
 * 002button.c
 *
 *  Created on: 20-Feb-2021
 *      Author: training
 */



#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"

#define HIGH
#define BTN_PRESSED 1
#define BTN_RELEASED LOW


void delay(void){

	for (uint32_t i=0; i<25000u; i++){

	}
}
int main(void){

	GPIO_Handle_t GpioLed,GpioBtn;
	GpioLed.pGPIOx = GPIOD;

	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	//GpioLed.GPIO_PinConfig.GPIO_PinPuPdControlr = GPIO_NO_PD;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);



    GpioBtn.pGPIOx = GPIOA;

		GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
		GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
		GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControlr = GPIO_NO_PD;
		GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

		GPIO_PeriClockControl(GPIOA, ENABLE);
		GPIO_Init(&GpioBtn);

	while(1){

		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BTN_PRESSED){

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);

			delay();
		// (GPIOD, GPIO_PIN_NO_12, 1)
		//GPIO_WriteFromInputPin(GpioLed.pGPIOx, GpioLed.GPIO_PinConfig.GPIO_PinNumber, ENABLE);
		}
	}




	return 0;
}

