/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   emuladordepuertos.h
 * Author: artola97
 *
 * Created on October 25, 2020, 7:54 PM
 */

#ifndef EMULADORDEPUERTOS_H
#define EMULADORDEPUERTOS_H

#include <stdint.h>

#define PORTA 'A'
#define PORTB 'B'
#define PORTD 'D'

typedef struct 
{
	uint8_t b0	:1;
	uint8_t b1	:1;
	uint8_t b2	:1;
	uint8_t b3	:1;
	uint8_t b4	:1;
	uint8_t b5	:1;
	uint8_t b6	:1;
	uint8_t b7	:1;
		
} bits8_t; //estructura para leer o escribir los bits del registro

typedef union
{
	bits8_t bit_port;
	uint8_t byte_port;
}byte_t;  // estructura de los registros A y B para el ingreso bit a bit o byte.

typedef union
{
    uint16_t portD;
    
    struct
    {
        byte_t portB;
        byte_t portA;
    }registries;
}port16b_t;// estructura del puerto de 16bits


int bitClr (char puerto, char bit);
/*Dado un puerto y un número de bit, debe cambiar su estado a 0*/

int bitGet (char puerto, char bit); 
/*Dado un puerto y un número de bit, debe devolver su valor.*/

int bitSet (char puerto, char bit);
/*Dado un puerto y un número de bit, debe cambiar su estado a 1.*/

int bitToggle(char puerto, char bit);
/*Dado  un  puerto  y  un  número  de  bit,  debe  cambiar  al  estado.*/

int maskOff (char puerto, char mask);
/*Dado un puerto y una máscara, debe apagar todos aquellos bits que estén  prendidos
 * en  la  máscara,  sin  cambiar  el  estado  de  los  restantes.  Por ejemplo, dado el puerto 
 * A, que originalmente se encuentra en el estado 0x0A, al aplicarle la máscara 0x02, el resultado será 0x08.*/

int maskOn (char puerto, char mask);
/*Dado un puerto y una máscara, debe prender todos aquellos
 * bits que estén  prendidos  en  la  máscara,
 * sin  cambiar  el  estado  de  los  restantes.  Por ejemplo,
 * dado el puerto A, que originalmente se encuentra en el estado 0x01, al
 * aplicarle la máscara 0x0A, el resultado será 0xB.*/

int maskToggle (char puerto, char bit);
/*Dado un puerto y una máscara, debe cambiar el estado
 * de todos aquellos  bits  que  estén  prendidos  en  la  máscara  
 * al  opuesto,  sin  cambiar  el estado de los restantes. Por ejemplo,
 * dado el puerto A, que originalmente se encuentra  en  el  estado  0x02,
 * al  aplicarle  la  máscara  0x03,  el  resultado  será 0x01.*/

int valbit (char puerto, char bit);

int valmask (char puerto, char mask);


#endif /* EMULADORDEPUERTOS_H */

