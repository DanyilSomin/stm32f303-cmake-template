#include "stm32f30x.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h" 

#include "FreeRTOS.h"
#include "task.h" 

GPIO_InitTypeDef gpio;

void initAll()
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_10 | GPIO_Pin_15 |
                    GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIO_Init(GPIOE, &gpio);
}

void prvTaskA (void* pvParameters)
{		
    (void) pvParameters;
	
    for (;;) 
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_15);
        GPIO_SetBits(GPIOE, GPIO_Pin_8);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_8);
        GPIO_SetBits(GPIOE, GPIO_Pin_9);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_9);
        GPIO_SetBits(GPIOE, GPIO_Pin_10);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_10);
        GPIO_SetBits(GPIOE, GPIO_Pin_11);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_11);
        GPIO_SetBits(GPIOE, GPIO_Pin_12);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_12);
        GPIO_SetBits(GPIOE, GPIO_Pin_13);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_13);
        GPIO_SetBits(GPIOE, GPIO_Pin_14);
        vTaskDelay(500);

		GPIO_ResetBits(GPIOE, GPIO_Pin_14);
        GPIO_SetBits(GPIOE, GPIO_Pin_15);
        vTaskDelay(500);
    }
}

int main (void)
{
    initAll();

    xTaskCreate( prvTaskA, "TaskA", configMINIMAL_STACK_SIZE, NULL,
        tskIDLE_PRIORITY, ( xTaskHandle * ) NULL );

    vTaskStartScheduler();

   //should never get here
   for (;;);
}