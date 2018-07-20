/* 
 * File:   main.c
 * Author: David McDermott
 *
 * Created on July 19, 2018, 8:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

//columns
//RA0 - 4
//RA1 - 3
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

    
    
    //Columns are written to
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISCbits.TRISC0 = 0;
    
    //Rows are read fromm
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
    
    PORTA.RA0 = 0;
    PORTA.RA1 = 0;
    PORTA.RA2 = 0;
    PORTC.RC0 = 0;
    
    for(;;){
        
        
    }
    
}

