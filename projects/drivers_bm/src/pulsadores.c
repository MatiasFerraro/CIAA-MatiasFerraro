/*
 * pulsadores.c
 *
 *  Created on: 15/01/16
 *      Author: Matias Leandro Ferraro
 */
#include "pulsadores.h"
#include "puertos.h"


void pulsadores_init(void){
	/*inicializo pulsadores*/
	port_pin(1,0, MD_PUP|MD_EZI|MD_ZI,init_in);
	port_pin(1,1, MD_PUP|MD_EZI|MD_ZI,init_in);
	port_pin(1,2, MD_PUP|MD_EZI|MD_ZI,init_in);
	port_pin(1,6, MD_PUP|MD_EZI|MD_ZI,init_in);
}

int estado_pulsador(uint8_t pulsador_n)
{
  switch(pulsador_n)
  {

    case TEC1: return !port_pin(1,0,disable,state_in);
               break;
    case TEC2: return !port_pin(1,1,disable,state_in);
               break;
    case TEC3: return !port_pin(1,2,disable,state_in);
               break;
    case TEC4: return !port_pin(1,6,disable,state_in);
               break;

  }
}







