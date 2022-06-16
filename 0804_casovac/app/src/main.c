#include "stm8s.h"

#define LED1 (GPIO_PIN_0)
#define LED2 (GPIO_PIN_1)
#define LED3 (GPIO_PIN_2)
#define LED4 (GPIO_PIN_3)
#define LED5 (GPIO_PIN_4)
#define LED6 (GPIO_PIN_5)
#define LED7 (GPIO_PIN_6)
#define LED8 (GPIO_PIN_7)
#define LEDOFF(LED) (GPIO_WriteHigh(GPIOB, LED))
#define LEDON(LED) (GPIO_WriteLow(GPIOB, LED))
#define tlac1 (GPIO_PIN_4)
#define tlac2 (GPIO_PIN_2)
#define tlac_stisk(tlac) (GPIO_ReadInputPin(GPIOD, tlac)==RESET)
#define len(arr) sizeof(arr)/sizeof(arr[0])

void delay(uint32_t iter);

void main(void) {
    GPIO_DeInit;
    TIM4_DeInit;
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV8); // FREQ MCU 2MHz
    // GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOC, LED6, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOE, tlac1, GPIO_MODE_IN_FL_IT);

    TIM4_TimeBaseInit(TIM4_PRESCALER_128, 255);
    TIM4_Cmd(ENABLE);
    // TIM4_Stav_ON = 1;
    int n = 0;

    while (1) {
        if(TIM4_GetFlagStatus(TIM4_FLAG_UPDATE)==SET) {
            TIM4_ClearFlag(TIM4_FLAG_UPDATE);
            n++;
        }
        if(n==60) {
            n = 0;
            GPIO_WriteReverse(GPIOC, LED6);
        }
    }
}



void delay(uint32_t iter)
{
    for(uint32_t i = 0; i < iter; i++);
}