
#ifndef _STM32F4XX_H_
#define _STM32F4XX_H_

#include <stdint.h>
#define  _vo volatile

//Defining Memory Base address

#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001C000U
#define FLASH_BASEADDR 0x08000000U
#define ROM_BASEADDR 0X1FFF0000U

//Defining Peripheral Base address

#define APB1_BASEADDR 0x40000000U
#define APB2_BASEADDR 0x40010000U
#define AHB1_BASEADDR 0x40020000U

//Defining peripherals base address that are hanging on the AHB bus

#define GPIOA_BASEADDR AHB1_BASEADDR
#define GPIOB_BASEADDR (AHB1_BASEADDR+0x0400U)
#define GPIOC_BASEADDR (AHB1_BASEADDR+0x0800U)
#define GPIOD_BASEADDR (AHB1_BASEADDR+0x0C00U)
#define GPIOE_BASEADDR (AHB1_BASEADDR+0x1000U)
#define RCC_BASEADDR   (AHB1_BASEADDR+0x3800U)

/*#define GPIOF_BASEADDR (AHB1_BASEADDR+0x1400U)
#define GPIOG_BASEADDR (AHB1_BASEADDR+0x1800U)
#define GPIOH_BASEADDR (AHB1_BASEADDR+0x1C00U)
#define GPIOI_BASEADDR (AHB1_BASEADDR+0x2000U)
#define GPIOJ_BASEADDR (AHB1_BASEADDR+0x2400U)
#define GPIOK_BASEADDR (AHB1_BASEADDR+0x2800U)
*/

//Defining peripherals base address that are hanging on the APB1 bus

#define TIM2_BASEADDR APB1_BASEADDR
#define TIM3_BASEADDR (APB1_BASEADDR+0x0400U)
#define TIM4_BASEADDR (APB1_BASEADDR+0x0800U)
#define TIM5_BASEADDR (APB1_BASEADDR+0x0C00U)
#define TIM6_BASEADDR (APB1_BASEADDR+0x1000U)
#define TIM7_BASEADDR (APB1_BASEADDR+0x1400U)
#define TIM12_BASEADDR (APB1_BASEADDR+0x1800U)
#define TIM13_BASEADDR (APB1_BASEADDR+0x1C00U)
#define TIM14_BASEADDR (APB1_BASEADDR+0x2000U)

//Defining peripherals base address that are hanging on the APB2 bus

#define TIM1_BASEADDR APB2_BASEADDR
#define TIM8_BASEADDR (APB2_BASEADDR+0x0400U)
#define USART1_BASEADDR (APB2_BASEADDR+0x1000U)
#define USART6_BASEADDR (APB2_BASEADDR+0x1400U)
#define SPI1_BASEADDR (APB2_BASEADDR+0x3000U)
#define SPI4_BASEADDR (APB2_BASEADDR+0x3400U)
#define TIM9_BASEADDR (APB2_BASEADDR+0x4000U)
#define TIM10_BASEADDR (APB2_BASEADDR+0x4400U)
#define TIM11_BASEADDR (APB2_BASEADDR+0x4800U)

#define ENABLE         1
#define DISABLE        0
#define SET            ENABLE
#define RESET          DISABLE
#define GPIO_PIN_SET   SET
#define GPIO_PIN_RESET RESET


//#define _vo volatile
typedef struct {

	_vo uint32_t MODER;
	_vo uint32_t OTYPER;
	_vo uint32_t OSPEEDR;
	_vo uint32_t PUPDR;
	_vo uint32_t IDR;
	_vo uint32_t ODRR;
	_vo uint32_t BSRR;
	_vo uint32_t LCKR;
	_vo uint32_t AFR[2];

}GPIO_RegDef_t; // GPIOE


typedef struct{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1;
	uint32_t RESERVED2;
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED3;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED4;
	uint32_t RESERVED5;
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED6;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED7;
	uint32_t RESERVED8;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED9;
	uint32_t RESERVED10;
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
}RCC_RegDef_t;

#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)

//GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t *) 0x40020000U;

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)

//Peripheral clock enable
#define GPIOA_PCLOCK_EN()   (RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLOCK_EN()   (RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLOCK_EN()   (RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLOCK_EN()   (RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLOCK_EN()   (RCC->AHB1ENR |=(1<<4))

//Peripheral clock disable
//TODO
/*#define GPIOA_PCLOCK_EN()  // (RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLOCK_EN()   //(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLOCK_EN()  // (RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLOCK_EN()  // (RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLOCK_EN()  // (RCC->AHB1ENR |=(1<<4))
*/

#define GPIOA_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<0)); (RCC->AHB1RSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<1)); (RCC->AHB1RSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<2)); (RCC->AHB1RSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<3)); (RCC->AHB1RSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<4)); (RCC->AHB1RSTR &= ~(1<<4));}while(0)
//#define GPIOF_REG_RESET()     do{(RCC->AHB1RSTR |=(1<<0)); (RCC->AHB1RSTR &= ~(1<<0));}while(0)


#endif




