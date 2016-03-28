/* Copyright 2015, Matias Leandro Ferraro
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "drivers_puertos.h"       /* <= own header */



#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */



int main(void)
{
// NOTA: El siguiente código se programó sin la capa de abstracción: leds.c y
	//	pulsadores.c para mostrar un ejemplo de la forma de acceso a un pin de un
	//	puerto con la función puerto_pin(...);


	port_pin(2,0, MD_PUP,init_out);
	port_pin(2,1, MD_PUP,init_out);
	port_pin(2,2, MD_PUP,init_out);
	port_pin(2,10,MD_PUP,init_out);
	port_pin(2,11,MD_PUP,init_out);
	port_pin(2,12,MD_PUP,init_out);

	port_pin(2,0, disable, low);
	port_pin(2,1, disable, low);
	port_pin(2,2, disable, low);
	port_pin(2,10,disable, low);
	port_pin(2,11,disable, low);
	port_pin(2,12,disable, low);

	port_pin(1,0, MD_PUP|MD_EZI|MD_ZI,init_in);
	port_pin(1,1, MD_PUP|MD_EZI|MD_ZI,init_in);
	port_pin(1,2, MD_PUP|MD_EZI|MD_ZI,init_in);
	port_pin(1,6, MD_PUP|MD_EZI|MD_ZI,init_in);

	while(1){
		if(!port_pin(1,0,disable,state_in))
		{ port_pin(2,0, disable, high);
		  port_pin(2,1, disable, high);
		  port_pin(2,2, disable, high);
	    }
		else{port_pin(2,0, disable, low);
			 port_pin(2,1, disable, low);
			 port_pin(2,2, disable, low);
		    }
	    if(!port_pin(1,1,disable,state_in))
		{
			port_pin(2,10, disable, high);
		}
	    else{port_pin(2,10, disable, low);
				            }
		if(!port_pin(1,2,disable,state_in))
		{
			port_pin(2,11, disable, high);
		}
		else{port_pin(2,11, disable, low);
				            }
		if(!port_pin(1,6,disable,state_in))
		{
		  port_pin(2,12, disable, high);
		}
		else{
		  port_pin(2,12, disable, low);
		    }
	}

    return 0;
}



/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

