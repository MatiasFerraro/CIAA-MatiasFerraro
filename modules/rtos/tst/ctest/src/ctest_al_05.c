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

/** \brief FreeOSEK OS Conformance Test for the Alarms, Test Sequence 5
 **
 ** \file FreeOSEK/Os/tst/ctest/src/ctest_al_05.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT_AL Alarms
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT_AL_05 Test Sequence 5
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090420 v0.1.0 MaCe initial version based on old moduletest
 */

/*==================[inclusions]=============================================*/
#include "os.h"            /* include os header file */
#include "ctest_al_05.h"   /* include test header file */
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

   ret = SetRelAlarm(Alarm1, 1, 0);
   ASSERT(OTHER, ret != E_OK);

   Sequence(1);
   /* \treq AL_31 mf B1B2E1E2 se Expiration of alarm wich activates a task
    * with higher priority than running task while running task is preemptive
    *
    * \result Task is activated. Task with highest priority is executed
    */
   IncAlarmCounter();
   ASSERT(AL_31, 0);

   Sequence(3);
   ChainTask(Task3);
}

TASK(Task2)
{
   static uint8 count = 0;

   switch (count)
   {
      case 0:
         /* increment call count */
         count++;

         Sequence(2);
         TerminateTask();
         /* This is intentional, the break; would be unreachable code, and TerminateTask(); */
         /* should not return a value. If this happens, the test will fail. */
      case 1:
         /* increment call count */
         count++;

         Sequence(8);

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

TASK(Task3)
{
   StatusType ret;
   TaskStateType TaskState;


   Sequence(4);
   ret = SetRelAlarm(Alarm1, 1, 0);
   ASSERT(OTHER, ret != E_OK);

   Sequence(5);
   /* \treq AL_32 mf B1B2E1E2 se Expiration of alarm wich activates a task
    * with lower priority than running task while running task is preemptive
    *
    * \result Task is activated. No preemption of running task
    */
   IncAlarmCounter();
   ASSERT(AL_32, 0);

   Sequence(6);
   ret = GetTaskState(Task2, &TaskState);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, TaskState != READY);

   Sequence(7);
   TerminateTask();
}

/* This task is not used, only to change the scheduling police */
TASK(Task4)
{
   TerminateTask();
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

