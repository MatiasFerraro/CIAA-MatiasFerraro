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

/** \brief FreeOSEK GetTaskState Implementation File
 **
 ** This file implements the GetTaskState API
 **
 ** \file GetTaskState.c
 **
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Global
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 * KLi          Kang Li
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090128 v0.1.2 MaCe add OSEK_MEMMAP check
 * 20081113 v0.1.1 KLi  Added memory layout attribute macros
 * 20080713 v0.1.0 MaCe initial version
 */

/*==================[inclusions]=============================================*/
#include "Os_Internal.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
StatusType GetTaskState
(
   TaskType TaskID,
   TaskStateRefType State
)
{
   /* \req OSEK_SYS_3.6 The system service StatusType
    ** GetTaskState ( TaskType TaskID, TaskStateRefType State ) shall be
    ** defined. */

   /* \req OSEK_SYS_3.6.3Possible return values in Standard mode is E_OK */
   StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
   /* check if TaskID is in a valid range */
   if ( TaskID >= TASKS_COUNT )
   {
      /* TaskID is out of range */
      /* return E_OS_ID */
      /* \req OSEK_SYS_3.6.4 Extra possible return values in Extended mode is
       ** E_OS_ID */
      ret = E_OS_ID;

      /* set invalid task value to the state */
      *State = TASK_ST_INVALID;
   }
   else
#endif
   {

      /* \req OSEK_SYS_3.6.1 The service shall returns the state of a task
       ** (running, ready, waiting, suspended) at the time of calling
       ** GetTaskState */
      /* \req OSEK_SYS_3.6.2 When the service is called for a task, which is
       ** activated more than once, the state is set to running if any instance
       ** of the task is running. */
      *State = (TaskStateType) TasksVar[TaskID].Flags.State;
   }

#if ( (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED) && \
      (HOOK_ERRORHOOK == OSEK_ENABLE) )
   /* \req OSEK_ERR_1.3-5/xx The ErrorHook hook routine shall be called if a
    ** system service returns a StatusType value not equal to E_OK.*/
   /* \req OSEK_ERR_1.3.1-5/xx The hook routine ErrorHook is not called if a
    ** system service is called from the ErrorHook itself. */
   if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
   {
      SetError_Api(OSServiceId_GetTaskState);
      SetError_Param1(TaskID);
      SetError_Param2((unsigned int)State);
      SetError_Ret(ret);
      SetError_Msg("GetTaskState returns != than E_OK");
      SetError_ErrorHook();
   }
#endif

   return ret;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

