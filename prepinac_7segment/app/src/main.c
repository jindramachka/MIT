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
#define tlac2 (GPIO_PIN_2)
#define tlac_stisk(tlac) (GPIO_ReadInputPin(GPIOD, tlac)==RESET)
#define len(arr) sizeof(arr)/sizeof(arr[0])
void no_exti(void);
void exti(void);
void delay(uint32_t iter);

INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
    GPIO_WriteReverse(GPIOC, LED6);
    
}

INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
    GPIO_WriteReverse(GPIOC, LED6);
}

void main(void) {
    GPIO_DeInit;
    EXTI_DeInit;
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    // GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOC, LED6, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOD, tlac1, GPIO_MODE_IN_PU_IT);
    GPIO_Init(GPIOB, tlac2, GPIO_MODE_IN_PU_IT);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTD, ITC_PRIORITYLEVEL_0);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTB, ITC_PRIORITYLEVEL_0);
    enableInterrupts();

    while (1) {

    }
    // }
    // exti();
}

void no_exti(void) {
    uint8_t akt_stav[2] = {0, 0};
    uint8_t pred_stav[2] = {0, 0};
    int nums[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98};
    // int nums[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10011000};

    int i = 0;

    while (1) {

        if (tlac_stisk(tlac1)) {akt_stav[0] = 1;} else {akt_stav[0] = 0;}
        if (tlac_stisk(tlac2)) {akt_stav[1] = 1;} else {akt_stav[1] = 0;}

        if (akt_stav[0] == 1 && pred_stav[0] == 0) {i++;}
        if (akt_stav[1] == 1 && pred_stav[1] == 0) {i--;}

        if (i < 0) {i = len(nums)-1;}
        else if (i > len(nums) - 1) {i = 0;}

        GPIO_Write(GPIOB, nums[i]);
        delay(50000);

        pred_stav[0] = akt_stav[0];
        pred_stav[1] = akt_stav[1];
    }
}

void exti(void) {
    uint8_t akt_stav[2] = {0, 0};
    uint8_t pred_stav[2] = {0, 0};
    int nums[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98};
    int i = 0;

    while (1) {

        if (tlac_stisk(tlac1)) {akt_stav[0] = 1;} else {akt_stav[0] = 0;}
        if (tlac_stisk(tlac2)) {akt_stav[1] = 1;} else {akt_stav[1] = 0;}

        if (akt_stav[0] == 1 && pred_stav[0] == 0) {GPIO_WriteHigh(GPIOC, LED6);}
        if (akt_stav[1] == 1 && pred_stav[1] == 0) {GPIO_WriteLow(GPIOC, LED6);}

        // if (i < 0) {i = len(nums)-1;}
        // else if (i > len(nums) - 1) {i = 0;}

        // GPIO_Write(GPIOB, nums[i]);

        delay(50000);

        pred_stav[0] = akt_stav[0];
        pred_stav[1] = akt_stav[1];
    }
}

void delay(uint32_t iter)
{
    for(uint32_t i = 0; i < iter; i++);
}