#include "stm32f30x.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"

#define DELAY_TIME 45

GPIO_InitTypeDef gpio;
unsigned int i;

static volatile uint32_t msTicks = 0;
void delay_ms(uint32_t dlyTicks);	

void initAll()
{
	SysTick_Config(SystemCoreClock / 1000);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_15 |
                    GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIO_Init(GPIOE, &gpio);
}


void SysTick_Handler (void) //Enter here every 1 ms
{
  msTicks++;
}

void delay_ms(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}

int main()
{
    initAll();
    
    while(1)
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_15);
        GPIO_SetBits(GPIOE, GPIO_Pin_8);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_8);
        GPIO_SetBits(GPIOE, GPIO_Pin_9);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_9);
        GPIO_SetBits(GPIOE, GPIO_Pin_10);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_10);
        GPIO_SetBits(GPIOE, GPIO_Pin_11);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_11);
        GPIO_SetBits(GPIOE, GPIO_Pin_12);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_12);
        GPIO_SetBits(GPIOE, GPIO_Pin_13);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_13);
        GPIO_SetBits(GPIOE, GPIO_Pin_14);
        delay_ms(DELAY_TIME);

		GPIO_ResetBits(GPIOE, GPIO_Pin_14);
        GPIO_SetBits(GPIOE, GPIO_Pin_15);
        delay_ms(DELAY_TIME);
    }
}