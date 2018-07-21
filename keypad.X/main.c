/* 
 * File:   main.c
 * Author: David McDermott
 *
 * Created on July 19, 2018, 8:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>

typedef struct Keys {
    
    unsigned one:1;
    unsigned two:1;
    unsigned three:1;
    unsigned A:1;
    
    unsigned four:1;
    unsigned five:1;
    unsigned six:1;
    unsigned B:1;
    
    unsigned seven:1;
    unsigned eight:1;
    unsigned nine:1;
    unsigned C:1;
    
    unsigned star:1;
    unsigned zero:1;
    unsigned hash:1;
    unsigned D:1;
} Keys;

//columns
//RA5 - 4
//RA4 - 3
//RA2 - 2
//RC0 - 1

//rows
//RC1 - 4
//RC2 - 3
//RC3 - 2
//RC4 - 1

/*
 * 
 */
int main(int argc, char** argv) {

    //No Analog
    ANSELA = 0;
    ANSELC = 0;
    
    //Columns are written to
    TRISCbits.TRISC5 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA2 = 0;
    TRISCbits.TRISC0 = 0;
    
    //Rows are read fromm
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
    
    //Start all digital writes to 0
    LATA = 0;
    LATC = 0;
    
    Keys pressed;
    for(;;){
        
        LATCbits.LATC5 = 1;
        pressed.one = PORTCbits.RC4;
        pressed.four = PORTCbits.RC3;
        pressed.seven = PORTCbits.RC2;
        pressed.star = PORTCbits.RC1;
        LATCbits.LATC5 = 0;
        
        LATAbits.LATA4 = 1;
        pressed.two = PORTCbits.RC4;
        pressed.five = PORTCbits.RC3;
        pressed.eight = PORTCbits.RC2;
        pressed.zero = PORTCbits.RC1;
        LATAbits.LATA4 = 0;
        
        LATAbits.LATA2 = 1;
        pressed.three = PORTCbits.RC4;
        pressed.six = PORTCbits.RC3;
        pressed.nine = PORTCbits.RC2;
        pressed.hash = PORTCbits.RC1;
        LATAbits.LATA2 = 0;
        
        LATCbits.LATC0 = 1;
        pressed.A = PORTCbits.RC4;
        pressed.B = PORTCbits.RC3;
        pressed.C = PORTCbits.RC2;
        pressed.D = PORTCbits.RC1;
        LATCbits.LATC0 = 0;
        
    }
    
}

