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

/** \brief FreeOSEK Os Conformance Test for the Event Mechanism, Test Sequence 3
 **
 ** \file FreeOSEK/Os/tst/ctest/src/ctest_em_03.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT_EM Event Mechanism
 ** @{ */
/** \addtogroup FreeOSEK_Os_CT_EM_03 Test Sequence 3
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090417 v0.1.0 MaCe initial version based on old moduletest
 */

/*==================[inclusions]=============================================*/
#include "os.h"            /* include os header file */
#include "ctest_em_03.h"   /* include test header file */
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
   EventMaskType EventMask;
   TaskStateType TaskState;

   Sequence(1);
   ret = GetTaskState(Task2, &TaskState);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, TaskState != WAITING);

   Sequence(2);
   ret = GetEvent(Task2, &EventMask);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, EventMask != 0);

   Sequence(3);
   /* \treq EM_05 nm E1E2 se Call SetEvent() from non preemptive task
    * on waiting extended task which is not waiting for any of the requested
    * events
    *
    * \result Requested events are set. Running task is not preempted. Waiting
    * task doesn't becomes ready. Service returns E_OK
    */
   ret = SetEvent(Task2, Event2);
   ASSERT(EM_05, ret != E_OK);

   Sequence(4);
   ret = GetTaskState(Task2, &TaskState);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, TaskState != WAITING);

   Sequence(5);
   ret = GetEvent(Task2, &EventMask);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, EventMask != Event2);

   Sequence(6);
   /* \treq EM_04 nm E1E2 se Call SetEvent() from non preemptive task
    * on waiting extended task which is waiting for at least one of the
    * requested events
    *
    * \result Requested events are set. Running task is not preempted. Waiting
    * task becomes ready. Service returns E_OK
    */
   ret = SetEvent(Task2, Event1);
   ASSERT(EM_04, ret != E_OK);

   Sequence(7);
   ret = GetTaskState(Task2, &TaskState);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, TaskState != READY);

   Sequence(8);
   ret = GetEvent(Task2, &EventMask);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, EventMask != ( Event1 | Event2 ) );

   Sequence(9);
   /* \treq EM_09 nm E1E2 se Call SetEvent() from non preemptive task
    * on waiting extended task
    *
    * \result Requested events are set. Running task is not preempted. Service
    * returns E_OK
    */
   ret = SetEvent(Task2, Event3);
   ASSERT(EM_09, ret != E_OK);

   Sequence(10);
   ret = GetEvent(Task2, &EventMask);
   ASSERT(OTHER, ret != E_OK);
   ASSERT(OTHER, EventMask != ( Event1 | Event2 | Event3 ) );

   Sequence(11);
   TerminateTask();
}

TASK(Task2)
{
   StatusType ret;

   Sequence(0);
   ret = WaitEvent(Event1);
   ASSERT(OTHER, ret != E_OK);

   Sequence(12);

   /* evaluate conformance tests */
   ConfTestEvaluation();

   /* finish the conformance test */
   ConfTestFinish();
}

/* This task is not used, only to change the scheduling police */
TASK(Task3)
{
   TerminateTask();
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

