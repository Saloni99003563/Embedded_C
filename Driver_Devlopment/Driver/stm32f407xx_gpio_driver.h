
#ifndef _STM32F407XX_GPIO_DRIVER_H_
#define _STM32F407XX_GPIO_DRIVER_H_


#include "stm32f4xx.h"

typedef struct{

uint8_t GPIO_PinNumber;
uint8_t GPIO_PinMode;
uint8_t GPIO_PinSpeed;
uint8_t GPIO_PinPuPdControlr;
uint8_t GPIO_PinOPType;
uint8_t GPIO_PinAltFuncMode;

}GPIO_PinConfig_t;

typedef struct{

GPIO_RegDef_t *pGPIOx;
GPIO_PinConfig_t  GPIO_PinConfig;

}GPIO_Handle_t;

// GPIO PIN numbers

#define GPIO_PIN_NO_0 0
#define GPIO_PIN_NO_1 1
#define GPIO_PIN_NO_2 2
#define GPIO_PIN_NO_3 3
#define GPIO_PIN_NO_4 4
#define GPIO_PIN_NO_5 5
#define GPIO_PIN_NO_6 6
#define GPIO_PIN_NO_7 7
#define GPIO_PIN_NO_8 8
#define GPIO_PIN_NO_9 9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15
#define GPIO_PIN_NO_16 16


#define GPIO_MODE_IN       0
#define GPIO_MODE_OUT      1
#define GPIO_MODE_ALTFN    2
#define GPIO_MODE_ANALOG   3

#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3

#define GPIO_OP_TYPE_PP    0
#define GPIO_OP_TYPE_OD    1


#define GPIO_NO_PUPD       0
#define GPIO_NO_PU         1
#define GPIO_NO_PD         2



/*
 *  to control clock
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 *  to initialize the GPIOxx
 */
void GPIO_Init(GPIO_Handle_t*);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 *  to Read input from GPIO ports and pins
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

/*
 *  to WRITE input from GPIO ports and pins
 */
void GPIO_WriteFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteFromInputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);

/*
 *  to Toggle the output pin
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber );



#endif
