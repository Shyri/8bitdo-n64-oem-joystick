/*
 * File:   main.c
 * Author: shyri
 *
 * Created on May 14, 2019, 10:01 PM
 */


// PIC12F675 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 16000000

// GPIO0: U/D
// GPIO1: N64 Q
// GPIO2: N64 I
// GPIO3: -
// GPIO4: INC
// GPIO5: CS


void __interrupt () isr (void) {
    if(GPIF == 1) {
        if(GPIO1 == GPIO2) {
            GPIO0 = 0;
            GPIO5 = 0;
            GPIO4 = 0;
            __delay_us(1);
            GPIO4 = 1;
            GPIO5 = 1;
            __delay_us(1);
        } else {
            GPIO0 = 1;
            GPIO5 = 0;
            GPIO4 = 0;
            __delay_us(1);
            GPIO4 = 1;
            GPIO5 = 1;
            __delay_us(1);
        }
    }
    
    GPIF = 0;
}

void calibrate(void) {
    GPIO4 = 0;
    __delay_ms(10);
    
    GPIO4 = 1;
    GPIO5 = 1;
    GPIO0 = 0;
    
    GPIO0 = 1;
    for(int i = 0; i < 99; i++) {
        GPIO5 = 0;
        GPIO4 = 0;
        __delay_ms(1);
        GPIO4 = 1;
        GPIO5 = 1;
        __delay_ms(1);
    }
    
    GPIO0 = 0;
    for(int i = 0; i < 49; i++) {
        GPIO5 = 0;
        GPIO4 = 0;
        __delay_ms(1);
        GPIO4 = 1;
        GPIO5 = 1;
        __delay_ms(1);
    }
}

void main(void) {
    TRISIO = 0b00000110; // Make GPIO2 an input
    CMCON = 0x07;        // Set comparator off
    ANSEL = 0;  
    ADCON0 = 0;
    
    __delay_ms(10);
    calibrate();
    
    GIE  = 1;
    GPIE = 1;
    IOC2 = 1;
    
    
    while(1) {
        
    }
}
