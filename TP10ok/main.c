/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: artola97
 *
 * Created on October 25, 2020, 7:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "emuladordepuertos.h"

/*
 * 
 */
int main(int argc, char** argv) 
{

    char c;
    while ((c=getchar())!='q')
    {
     switch (c)
     {
         case 't': 
             maskToggle(PORTA, 0xFF); 
             led_state (PORTA);
             break;
         case 'c':
             maskOff (PORTA, 0xFF);
             led_state (PORTA);
             break;
         case 's':
             maskOn (PORTA, 0xFF);
             led_state (PORTA);
             break;
         case 0: 
             switchcase (0, PORTA);
             led_state (PORTA);
             break;
         case '1':
         switchcase (1, PORTA);
             led_state (PORTA);
             break;
         case '2': 
             switchcase (2, PORTA);
             led_state (PORTA);
             break;
         case '3': 
             switchcase (3, PORTA);
             led_state (PORTA);
             break;
         case '4':
             switchcase (4, PORTA);
             led_state (PORTA);
             break;
         case '5': 
             switchcase (5,PORTA);
             led_state (PORTA);
             break;
         case '6': 
             switchcase (6, PORTA);
             led_state (PORTA);
             break;
         case '7':
             switchcase (7, PORTA);
             led_state (PORTA);
             break;
         default: break;
     }
    }
    return (EXIT_SUCCESS); 
}

int switchcase (char bit , char puerto)// 0, portA
{
     if (bitGet(bit, puerto))
        bitClr (bit, puerto);
     else 
        bitSet (bit, puerto);
}



