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
#define tlac1 (GPIO_PIN_0)
#define tlac2 (GPIO_PIN_1)
#define tlac3 (GPIO_PIN_2)
#define tlac4 (GPIO_PIN_3)
#define tlac_stisk(tlac) (GPIO_ReadInputPin(GPIOG, tlac)==RESET)
#define len(arr) sizeof(arr)/sizeof(arr[0])

void delay(uint32_t iter)
{
    for(uint32_t i = 0; i < iter; i++);
}

void main(void) {
    GPIO_DeInit;
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOE, tlac4, GPIO_MODE_IN_PU_NO_IT);
    int nums[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98};
    // int nums[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10011000};


    while (1) {
        for(int i=0; i<len(nums); i++) {
            GPIO_Write(GPIOB, nums[i]);
            delay(800000);
        }
    }
}