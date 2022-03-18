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
#define len(arr) sizeof(arr)/sizeof(arr[0])
#define tlac1 (GPIO_PIN_0)
#define tlac2 (GPIO_PIN_1)
#define tlac3 (GPIO_PIN_2)
#define tlac4 (GPIO_PIN_3)
#define tlac_stisk(tlac) (GPIO_ReadInputPin(GPIOG, tlac)==RESET)
void delay(uint32_t iterations);


int akt_led = 0;

void main(void)
{
    GPIO_DeInit;
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV8); // FREQ MCU 16MHz
    GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOG, GPIO_PIN_ALL, GPIO_MODE_IN_PU_IT);

    GPIO_Pin_TypeDef LEDS[8] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
    uint8_t akt_stav[2] = {0, 0};
    uint8_t pred_stav[2] = {0, 0};
    uint8_t citac_pwm = 0;
    uint8_t pwm_led = 255;

    LEDON(LEDS[akt_led]);

    while(1) {

        if(tlac_stisk(tlac1)) {

            int pred_led = akt_led;
            akt_led++;

            if(akt_led > (len(LEDS))) {
                akt_led = 0;
            }
            citac_pwm = 0;
            pwm_led = 255;

            LEDOFF(LEDS[pred_led]);
            LEDON(LEDS[akt_led]);
            delay(100*300);
        }

        if(tlac_stisk(tlac2)) {
            int pred_led = akt_led;
            akt_led--;

            if(akt_led+8 == len(LEDS)-1) {
                akt_led=8;
            }
            citac_pwm = 0;
            pwm_led = 255;

            LEDOFF(LEDS[pred_led]);
            LEDON(LEDS[akt_led]);
            delay(100*300);
        }

        if (tlac_stisk(tlac3)) {akt_stav[0] = 1;} else {akt_stav[0] = 0;}
        if (tlac_stisk(tlac4)) {akt_stav[1] = 1;} else {akt_stav[1] = 0;}

        if (akt_stav[0] == 1 && pred_stav[0] == 0) {pwm_led-=15;}
        if (akt_stav[1] == 1 && pred_stav[1] == 0) {pwm_led+=15;}
        
        if(pwm_led > citac_pwm) {LEDON(LEDS[akt_led]);} else {LEDOFF(LEDS[akt_led]);}

        citac_pwm++;
        pred_stav[0] = akt_stav[0];
        pred_stav[1] = akt_stav[1];
    }
}

void delay(uint32_t iterations) {
    for(uint32_t i = 0; i < iterations; i++);
}