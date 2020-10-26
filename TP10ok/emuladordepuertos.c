/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "emuladordepuertos.h"

#define MASCARA 0x01

//variable global
static port16b_t puertos;

int bitSet (char puerto, char bit)
{
    int mask=MASCARA;
    mask<<=bit;
    int val;
    val = valbit (puerto, bit);
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            puertos.registries.portA |= mask;
            break;
        case 'B':
            puertos.registries.portB |= mask;
            break;
        case 'D':
            puertos.portD |= mask;
            break;
         default: break;
        }   
   }
   return val;
}

int bitClr (char puerto, char bit)
{
    int mask=MASCARA;
    mask<<=bit;
    mask=~mask;
    int val;
    val = valbit (puerto, bit);
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            puertos.registries.portA &= mask;
            break;
        case 'B':
            puertos.registries.portB &= mask;
            break;
        case 'D':
            puertos.portD &= mask;
            break;
         default: break;
        }   
   } 
   return val;
}

int bitGet (char puerto, char bit)
{
    int mask=MASCARA;
    mask<<=bit;
    int val;
    val = valbit (puerto, bit);
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            val=puertos.registries.portA;
            break;
        case 'B':
            val=puertos.registries.portB;
            break;
        case 'D':
            val=puertos.portD;
            break;
         default: break;
        }   
   }
   return val;
}

int bitToggle (char puerto, char bit)
{
    int mask=MASCARA;
    mask<<=bit;
    int val;
    val = valbit (puerto, bit);
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            puertos.registries.portA |= mask;
            break;
        case 'B':
            puertos.registries.portB |= mask;
            break;
        case 'D':
            puertos.portD |= mask;
            break;
         default: break;
        }   
   }
   return val;
}

int maskOn (char puerto, char mask)
{
    int val;
    val = valmask (puerto, mask);
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            puertos.registries.portA |= mask;
            break;
        case 'B':
            puertos.registries.portB |= mask;
            break;
        case 'D':
            puertos.portD |= mask;
            break;
         default: break;
        }   
   }
   return val;
}

int maskOff (char puerto, char mask)
{
    int val;
    val = valmask (puerto, mask);
    mask=~mask;
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            puertos.registries.portA &= mask;
            break;
        case 'B':
            puertos.registries.portB &= mask;
            break;
        case 'D':
            puertos.portD &= mask;
            break;
         default: break;
        }   
   }
   return val;
}

int maskToggle (char puerto, char mask)
{
    int val;
    val = valmask (puerto, mask);
    if (val)
     {    
       switch (puerto)
        {   
        case 'A':
            puertos.registries.portA ^= mask;
            break;
        case 'B':
            puertos.registries.portB ^= mask;
            break;
        case 'D':
            puertos.portD ^= mask;
            break;
         default: break;
        }   
   }
   return val;
}

void led_state (char puerto)
{
    int i;
    switch (puerto)
    {
        case 'A':
        for (i=7; i>=0; i--)   
        {
           printf ("LED %d: %d\n", i, bitGet (PORTA, i));
        } 
        break;
        case 'B':
        for (i=7; i>=0; i--)   
        {
           printf ("LED %d: %d\n", i, bitGet (PORTB, i));
        }
        break;
        case 'D':
        for (i=15; i>=0; i--)   
        {
           printf ("LED %d: %d\n", i, bitGet (PORTD, i));
        }
        break;
        default: break;
    }        
    
  
}

int valbit (char puerto, char bit)
{
    int val;
    if ((bit>7 || bit<0) || (puerto != PORTA) || (puerto != PORTB) || (puerto != PORTD))
    {
        val=0;
    }
    else 
    {    
        val=1;
    }    
    return val;
    
}

int valmask (char puerto, char mask)
{
    int val;
    if ((puerto != PORTA) || (puerto != PORTB) || (puerto != PORTD))
    {
        val=0;
    }
    else 
    {
        val=1;
    }
    return val;
}
