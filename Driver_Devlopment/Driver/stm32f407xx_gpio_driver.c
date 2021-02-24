#include "stm32f407xx_gpio_driver.h"

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){

	if(pGPIOx == GPIOA){

		GPIOA_PCLOCK_EN();

	}else if(pGPIOx == GPIOB){

		GPIOB_PCLOCK_EN();
	}else if(pGPIOx == GPIOC){

		GPIOC_PCLOCK_EN();
	}else if(pGPIOx == GPIOD){

		GPIOD_PCLOCK_EN();
	}else if(pGPIOx == GPIOE){

		GPIOE_PCLOCK_EN();
	}

}

/*
 *  to initialize the GPIOxx
 */
void GPIO_Init(GPIO_Handle_t* pGPIOHandle){

	// 1. Configuration of pin mode of GPIOx
	uint32_t temp=0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER &=~(0x03 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER |= temp;

	// 2. Configuration of speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &=~(0x03<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR|= temp;

	// 3. configuration of pull-up and pull-down

	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControlr << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &=~(0x03 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR|= temp;

	//4. GPIO port input data register
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &=~(0x1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER|= temp;

	//5. GPIO alternate function low register
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){

		uint8_t temp1,temp2;

			temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
			temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
			pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xf << (4*temp2));
			pGPIOHandle->pGPIOx->AFR[temp1] |= pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFuncMode << (4*temp2);
	}


}



void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

	if(pGPIOx== GPIOA){
		GPIOA_REG_RESET();

	}else if(pGPIOx== GPIOB){
		GPIOB_REG_RESET();

	}else if(pGPIOx== GPIOC){

		GPIOC_REG_RESET();
	}
	else if(pGPIOx== GPIOD){
			GPIOD_REG_RESET();
		}
	else if(pGPIOx== GPIOE){
			GPIOE_REG_RESET();
		}else{

		}

}

/*
 *  to Read input from GPIO ports and pins
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	uint8_t value;
	value =  (uint8_t)((pGPIOx->IDR >> PinNumber ) & 0X00000001);

return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = pGPIOx-> IDR;
	return value;
}

/*
 *  to WRITE input from GPIO ports and pins
 */
void GPIO_WriteFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value){

	if(value == GPIO_PIN_SET){

		pGPIOx->ODRR |= (1<<PinNumber);
	}else {
		pGPIOx->ODRR &= ~(1<<PinNumber);
	}

}
void GPIO_WriteFromInputPort(GPIO_RegDef_t *pGPIOx, uint16_t value){

	pGPIOx->ODRR =value;

}

/*
 *  to Toggle the output pin
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber ){

	pGPIOx->ODRR ^= (1<<PinNumber);

}
