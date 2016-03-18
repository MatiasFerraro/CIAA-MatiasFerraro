/*
 * CIAA_F_salidas_digitales.c
 *
 *  Created on: 07/03/16
 *      Author: Matias Leandro Ferraro
 */
#include "CIAA_F_salidas_digitales.h"

void rele_init(void)
{
     /*Inicializo salidas a relé*/
	 port_pin(4,4, MD_PUP,init_out);
	 port_pin(4,5, MD_PUP,init_out);
     port_pin(4,6, MD_PUP,init_out);
	 port_pin(2,1,MD_PUP,init_out);

	 /*desenergizo las bobinas de los relés*/
	 port_pin(4,4, disable, low);
	 port_pin(4,5, disable, low);
	 port_pin(4,6, disable, low);
	 port_pin(2,1,disable,  low);
}

void open_drain_init(void)
{
	/*inicializo salidas open drain*/
	 port_pin(4,8, MD_PUP,init_out);
	 port_pin(4,9, MD_PUP,init_out);
	 port_pin(4,10, MD_PUP,init_out);
	 port_pin(1,5,MD_PUP,init_out);

	 /*salidas open drain OFF*/
	 port_pin(4,8, disable, high);
     port_pin(4,9, disable, high);
	 port_pin(4,10, disable,high);
	 port_pin(1,5,disable,  high);
}

void rele_on(uint8_t rele_n)
{
  switch(rele_n)
  {

    case DOUT0: port_pin(4,4, disable, high);
                break;
    case DOUT1: port_pin(4,5, disable, high);
                break;
    case DOUT2: port_pin(4,6, disable, high);
                break;
    case DOUT3: port_pin(2,1, disable, high);
                break;
  }
}
void rele_off(uint8_t rele_n)
{
  switch(rele_n)
  {
    case DOUT0: port_pin(4,4, disable, low);
                break;
    case DOUT1: port_pin(4,5, disable, low);
                break;
    case DOUT2: port_pin(4,6, disable, low);
                break;
    case DOUT3: port_pin(2,1, disable, low);
                break;
  }
}
void open_drain_on(uint8_t drain_n)
{
  switch(drain_n)
  {
    case DOUT4: port_pin(4,8, disable, low);
                break;
    case DOUT5: port_pin(4,9, disable, low);
                break;
    case DOUT6: port_pin(4,10, disable,low);
                break;
    case DOUT7: port_pin(1,5,  disable,low);
                break;
  }
}
void open_drain_off(uint8_t drain_n)
{
  switch(drain_n)
  {
    case DOUT4: port_pin(4,8, disable, high);
                break;
    case DOUT5: port_pin(4,9, disable, high);
                break;
    case DOUT6: port_pin(4,10, disable,high);
                break;
    case DOUT7: port_pin(1,5,  disable,high);
                break;
  }
}

