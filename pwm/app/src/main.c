#include "stm8s.h"

// void main(void)
// {
//     CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
//     GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
//     GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_SLOW);
//     GPIO_Init(GPIOE, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
//     GPIO_Init(GPIOG, GPIO_PIN_4, GPIO_MODE_IN_PU_NO_IT);

//     while (1)
//     {
//         if (GPIO_ReadInputPin(GPIOE, GPIO_PIN_4)==RESET || GPIO_ReadInputPin(GPIOG, GPIO_PIN_4)==RESET)
//         {
//             GPIO_WriteLow(GPIOB, GPIO_PIN_0);
//             for (uint32_t i = 0; i < 100000; i++);
//             GPIO_WriteReverse(GPIOB, GPIO_PIN_0);
//             for (uint32_t i = 0; i < 100000; i++);
//         } else {
//             GPIO_WriteLow(GPIOB, GPIO_PIN_0);
//         }
//     }
// }

// void main(void)
// {
//     GPIO_DeInit(GPIOB);
//     CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
//     GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_SLOW);
//     uint8_t citac_pwm = 0;
//     uint8_t pwm_led = 255;

//     while (1)
//     {
//         if(pwm_led > citac_pwm) {
//             GPIO_WriteLow(GPIOB, GPIO_PIN_0);
//         } else {
//             GPIO_WriteHigh(GPIOB, GPIO_PIN_0);
//         }
//         if (citac_pwm == 255) {
//             citac_pwm = 0;
//             pwm_led -= 1;
//         }  
//         for(uint8_t i = 0; i < 50; i++);
//         citac_pwm++;
//     }
// }

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOE, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(GPIOG, GPIO_PIN_4, GPIO_MODE_IN_PU_NO_IT);
    uint8_t citac_pwm = 0;
    uint8_t pwm_led = 255;

    while (1)
    {
        if (GPIO_ReadInputPin(GPIOE, GPIO_PIN_4)==RESET || GPIO_ReadInputPin(GPIOG, GPIO_PIN_4)==RESET)
        {
            // GPIO_WriteLow(GPIOB, GPIO_PIN_0);
            // for (uint32_t i = 0; i < 100000; i++);
            // GPIO_WriteReverse(GPIOB, GPIO_PIN_0);
            // for (uint32_t i = 0; i < 100000; i++);
            if(pwm_led > citac_pwm) {
                GPIO_WriteHigh(GPIOB, GPIO_PIN_0);
            } else {
                GPIO_WriteLow(GPIOB, GPIO_PIN_0);
            }
            if (citac_pwm == 255) {
                citac_pwm = 0;
                pwm_led -= 1;
            }  
            for(uint8_t i = 0; i < 50; i++);
            citac_pwm++;
        } else {
            GPIO_WriteLow(GPIOB, GPIO_PIN_0);
        }
    }
}
