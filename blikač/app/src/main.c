#include "stm8s.h"
#include "__assert__.h"

// #define LED1 (GPIO_PIN_0)
// #define LED2 (GPIO_PIN_1)
// #define LED3 (GPIO_PIN_2)
// #define LED4 (GPIO_PIN_3)
// #define LED5 (GPIO_PIN_4)
// #define LED6 (GPIO_PIN_5)
// #define LED7 (GPIO_PIN_6)
// #define LED8 (GPIO_PIN_7)
// #define len(arr) sizeof(arr)/sizeof(arr[0])

// void reverseArr(GPIO_Pin_TypeDef arr[4])
// {
//     int start = 0;
//     int end = 3;
//     while (start < end) {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }

// void main(void)
// {
//     GPIO_DeInit(GPIOB);
//     CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
//     GPIO_Pin_TypeDef LEDS[8] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8}; 
//     GPIO_Pin_TypeDef LEDS1[4] = {LED1, LED2, LED3, LED4}; 
//     GPIO_Pin_TypeDef LEDS2[4] = {LED8, LED7, LED6, LED5}; 
//     GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);

//     while (1)
//     {
//         // for (int j = 0; j < 2; j++) {
//         //     for (int i = 0; i < len(LEDS); i++) {
//         //         GPIO_WriteReverse(GPIOB, LEDS[i]);
//         //         for (uint32_t i = 0; i < 100000; i++);
//         //     }
//         // }
//         // reverseArr(LEDS);
        
//         for (int j = 0; j < 2; j++) {
//             for (int i = 0; i < 4; i++) {
//                 GPIO_WriteReverse(GPIOB, LEDS1[i]);
//                 GPIO_WriteReverse(GPIOB, LEDS2[i]);
//                 for (uint32_t i = 0; i < 100000; i++);
//             }
//         }
        
//         reverseArr(LEDS1);
//         reverseArr(LEDS2);
//     }
// }

// #define LED1 (GPIO_PIN_0)
// #define LED2 (GPIO_PIN_1)
// #define LED3 (GPIO_PIN_2)
// #define LED4 (GPIO_PIN_3)
// #define LED5 (GPIO_PIN_4)
// #define LED6 (GPIO_PIN_5)
// #define LED7 (GPIO_PIN_6)
// #define LED8 (GPIO_PIN_7)
// #define len(arr) sizeof(arr)/sizeof(arr[0])
void main(void)
{
    GPIO_DeInit(GPIOB);
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    // GPIO_Pin_TypeDef LEDS[8] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8}; 
    // GPIO_Pin_TypeDef LEDS1[4] = {LED1, LED2, LED3, LED4}; 
    // GPIO_Pin_TypeDef LEDS2[4] = {LED8, LED7, LED6, LED5}; 
    GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);
    uint8_t citac_pwm = 0;
    uint8_t pwm_led = 0;

    while (1)
    {
;       if(pwm_led > citac_pwm) {
            GPIO_WriteHigh(GPIOB, GPIO_PIN_0);
        } else {
            GPIO_WriteLow(GPIOB, GPIO_PIN_0);
        }  
        for(uint8_t i = 1; i < 200; i++);
        citac_pwm++;
    }
}