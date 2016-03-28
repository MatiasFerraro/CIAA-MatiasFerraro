/* Copyright 2008, 2009, 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
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

#ifndef _CTEST_ARCH_H_
#define _CTEST_ARCH_H_
/** \brief FreeOSEK Os Conformance Test
 **
 ** \file FreeOSEK/Os/tst/ctest/inc/posix/ctest_arch.h
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT Conformance Test
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 * JuCe         Juan Cecconi
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20141123 v0.1.0 JuCe   implements ISR1/ISR2 triggers
 * 20140503 v0.1.0 MaCe   initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaaPlatforms.h"

/*==================[macros]=================================================*/
#if (CPUTYPE == lpc43xx)
/* Use GPIO0, IRQ32 as interrupt for tests */
extern void TriggerISR2_Arch(void);

/* Use GPIO1, IRQ33 as interrupt for tests */
extern void TriggerISR1_Arch(void);

#elif (CPUTYPE == k60_120)

/* Use PORTC, IRQ88 as interrupt for tests */
#define TriggerISR2_Arch()                                                \
{                                                                          \
   NVIC_SetPendingIRQ(88);                                                 \
}

/* Use PORTB, IRQ87 as interrupt for tests */
#define TriggerISR1_Arch()                                                \
{                                                                          \
   NVIC_SetPendingIRQ(87);                                                 \
}

#else
   #error please define CPU variable!
#endif

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _CTEST_ARCH_H_ */

