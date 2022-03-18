// #include "stm8s.h"

// #define LED1 (GPIO_PIN_0)
// #define LED2 (GPIO_PIN_1)
// #define LED3 (GPIO_PIN_2)
// #define LED4 (GPIO_PIN_3)
// #define LED5 (GPIO_PIN_4)
// #define LED6 (GPIO_PIN_5)
// #define LED7 (GPIO_PIN_6)
// #define LED8 (GPIO_PIN_7)
// #define LEDOFF(LED) (GPIO_WriteHigh(GPIOB, LED))
// #define LEDON(LED) (GPIO_WriteLow(GPIOB, LED))
// #define len(arr) sizeof(arr)/sizeof(arr[0])
// #define tlac1 (GPIO_PIN_0)
// #define tlac2 (GPIO_PIN_1)
// #define tlac3 (GPIO_PIN_2)
// #define tlac4 (GPIO_PIN_3)
// #define tlac_stisk(tlac) (GPIO_ReadInputPin(GPIOG, tlac)==RESET)

// void delay(uint32_t iterations)
// {
//     iterations *= 110;

//     for(uint32_t i = 0; i < iterations; i++);
// }

// void main(void)
// {
//     CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
//     GPIO_Pin_TypeDef LEDS[8] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
//     for (uint8_t i=0; i<len(LEDS); i++) {
//         GPIO_Init(GPIOB, LEDS[i], GPIO_MODE_OUT_PP_HIGH_SLOW);
//     }
//     GPIO_Init(GPIOG, tlac1, GPIO_MODE_IN_PU_NO_IT);
//     GPIO_Init(GPIOG, tlac2, GPIO_MODE_IN_PU_NO_IT);
//     GPIO_Init(GPIOG, tlac3, GPIO_MODE_IN_PU_NO_IT);
//     GPIO_Init(GPIOG, tlac4, GPIO_MODE_IN_PU_NO_IT);

    
//     // uint8_t citac_pwm[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//     // uint8_t pwm_led[8] = {125, 125, 125, 125, 125, 125, 125, 125};
//     uint8_t citac_pwm = 0;
//     uint8_t pwm_led = 225;
//     int akt_stav[4] = {0, 0, 0, 0};
//     int pred_stav[4] = {0, 0, 0, 0};
//     int j = 0;

//     while (1) {

//         if (tlac_stisk(tlac1)) {akt_stav[0] = 1;} else {akt_stav[0] = 0;}
//         if (tlac_stisk(tlac2)) {akt_stav[1] = 1;} else {akt_stav[1] = 0;}
//         if (tlac_stisk(tlac3)) {akt_stav[2] = 1;} else {akt_stav[2] = 0;}
//         if (tlac_stisk(tlac4)) {akt_stav[3] = 1;} else {akt_stav[3] = 0;}

//         if (akt_stav[2] == 1 && pred_stav[2] == 0) {pwm_led-=15;}
//         if (akt_stav[3] == 1 && pred_stav[3] == 0) {pwm_led+=15;}
        
//         if (akt_stav[0] == 1 && pred_stav[0] == 0) {
//             if (j+1 > len(LEDS)-1) {j=0;} else {j++;}
//         }

//         if(pwm_led > citac_pwm) {LEDON(LEDS[j]);} else {LEDOFF(LEDS[j]);}

//         for(uint8_t i = 0; i < 100; i++);
//         citac_pwm++;

//         pred_stav[0] = akt_stav[0];
//         pred_stav[1] = akt_stav[1];
//         pred_stav[2] = akt_stav[2];
//         pred_stav[3] = akt_stav[3];
//     }
// }

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

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz

    GPIO_Init(GPIOB, LED1, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOG, tlac1, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOG, tlac2, GPIO_MODE_IN_PU_NO_IT);

    uint8_t citac_pwm = 0;
    uint8_t pwm_led = 225;
    uint8_t akt_stav[2] = {0, 0};
    uint8_t pred_stav[2] = {0, 0};

    while (1) {
        if (tlac_stisk(tlac1)) {akt_stav[0] = 1;} else {akt_stav[0] = 0;}
        if (tlac_stisk(tlac2)) {akt_stav[1] = 1;} else {akt_stav[1] = 0;}

        if (akt_stav[0] == 1 && pred_stav[0] == 0) {pwm_led-=15;}
        if (akt_stav[1] == 1 && pred_stav[1] == 0) {pwm_led+=15;}
        
        if(pwm_led > citac_pwm) {LEDON(LED1);} else {LEDOFF(LED1);}

        delay(100);
        citac_pwm++;
        pred_stav[0] = akt_stav[0];
        pred_stav[1] = akt_stav[1];
    }
}