/* Copyright 2008, 2009 Mariano Cerdeiro
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

/** \brief FreeOSEK Os Conformance Test for the Task Managment, Test Sequence 12
 **
 ** \file FreeOSEK/Os/tst/ctest/src/ctest_tm_12.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT_TM_12 Test Sequence 12
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090414 v0.1.0 MaCe initial version
 */

/*==================[inclusions]=============================================*/
#include "os.h"            /* include os header file */
#include "ctest_tm_12.h"   /* include test header file */
#include "ctest.h"         /* include ctest header file */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
const uint32f SequenceCounterOk = MAX_SEQUENCE;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
int main
(
   void
)
{
   /* start OS in AppMode 1 */
   StartOS(AppMode1);

   /* shall never return */
   while(1);

   return 0;
}

TASK(Task1)
{
   StatusType ret;

   Sequence(0);
   ret = ActivateTask(Task2);
   ASSERT(OTHER, ret != E_OK);

   Sequence(1);
   ret = ActivateTask(Task3);
   ASSERT(OTHER, ret != E_OK);

   Sequence(2);
   ret = ActivateTask(Task2);
   ASSERT(OTHER, ret != E_OK);

   Sequence(3);
   ret = ActivateTask(Task2);
   ASSERT(OTHER, ret != E_OK);

   Sequence(4);
   ret = ActivateTask(Task3);
   ASSERT(OTHER, ret != E_OK);

   Sequence(5);
   ret = ActivateTask(Task3);
   ASSERT(OTHER, ret != E_OK);

   Sequence(6);
   TerminateTask();

}

TASK(Task2)
{
   static uint8 count = 0;

   switch (count)
   {
      case 0:
         /* increment task call counter */
         count++;

         Sequence(7);
         TerminateTask();
         break;
      case 1:
         /* increment task call counter */
         count++;

         Sequence(9);
         TerminateTask();
         break;
      case 2:
         /* increment task call counter */
         count++;

         Sequence(10);
         TerminateTask();
         break;
      default:
         while(1);
         break;
   }
}

TASK(Task3)
{
   static uint8 count = 0;

   switch (count)
   {
      case 0:
         /* increment task call counter */
         count++;

         Sequence(8);
         TerminateTask();
         break;
      case 1:
         /* increment task call counter */
         count++;

         Sequence(11);
         TerminateTask();
         break;
      case 2:
         /* increment task call counter */
         count++;

         Sequence(12);

         /* evaluate conformance tests */
         ConfTestEvaluation();

         /* finish the conformance test */
         ConfTestFinish();
         break;
      default:
         while(1);
         break;
   }
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

