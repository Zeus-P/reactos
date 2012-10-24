/*
 * server.c - ReactOS/Win32 Console+User Enviroment Subsystem Server - Initialization
 *
 * ReactOS Operating System
 *
 * --------------------------------------------------------------------
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * --------------------------------------------------------------------
 *
 * PROGRAMMER: Eric Kohl
 */

/* INCLUDES ******************************************************************/

#include "winsrv.h"

//#define NDEBUG
#include <debug.h>


/* GLOBALS *******************************************************************/

static BOOLEAN ServicesProcessIdValid = FALSE;
static ULONG_PTR ServicesProcessId;


/* FUNCTIONS *****************************************************************/

CSR_API(SrvRegisterServicesProcess)
{
    if (ServicesProcessIdValid == TRUE)
    {
        /* Only accept a single call */
        return STATUS_INVALID_PARAMETER;
    }
    else
    {
        ServicesProcessId = (ULONG_PTR)ApiMessage->Data.RegisterServicesProcessRequest.ProcessId;
        ServicesProcessIdValid = TRUE;
        return STATUS_SUCCESS;
    }
}

/* EOF */
