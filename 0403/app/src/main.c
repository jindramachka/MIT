#include "stm8s.h"

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOE, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(GPIOG, GPIO_PIN_4, GPIO_MODE_IN_PU_NO_IT);

    while (1)
    {
        GPIO_WriteReverse(GPIOC, GPIO_PIN_5);
        for (uint32_t i = 0; i < 100000; i++);
    }
}
