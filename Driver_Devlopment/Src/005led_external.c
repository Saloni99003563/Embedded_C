/*
 * 005led_external.c
 *
 *  Created on: Feb 22, 2021
 *      Author: training
 */




#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"

#define HIGH 		1
#define BTN_PRESSED HIGH



void delay(void)
{
	for(uint32_t i=0;i<500000;i++)
	{

	}
}

int main(void)
{
	/*
	 * RGB Led
	 */
	GPIO_Handle_t GpioLedR, GpioLedG, GpioLedB;

	// Led R
	GpioLedR.pGPIOx= GPIOD;
	GpioLedR.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GpioLedR.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedR.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLedR.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedR);

	// Led G
	GpioLedG.pGPIOx= GPIOD;
	GpioLedG.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4;
	GpioLedG.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedG.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLedG.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedG);

	// Led B
	GpioLedB.pGPIOx= GPIOD;
	GpioLedB.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	GpioLedB.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedB.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLedB.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedB);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_2);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_4);
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_6);
		delay();
	}
	return(0);
}
