/*******************************************************************************
  Capture/Compare/PWM/Timer Module (CCP3) Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ccp3.c

  Summary:
    CCP3 Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
#include "plib_ccp3.h"

static CCP_TIMER_OBJECT ccp3TimerObj;
static CCP_CAPTURE_OBJECT ccp3CaptureObj;
// *****************************************************************************

// *****************************************************************************
// Section: CCP3 Implementation
// *****************************************************************************
// *****************************************************************************

void CCP3_CaptureInitialize (void)
{
    /* Disable Timer */
    CCP3CON1CLR = _CCP3CON1_ON_MASK;

    CCP3CON1 = 0x0;

    CCP3CON2 = 0x0;

    CCP3CON3 = 0x0;

    /* Enable Timer overflow interrupt */
    IEC2SET = _IEC2_CCT3IE_MASK;
    /* Enable input capture interrupt */
    IEC2SET = _IEC2_CCP3IE_MASK;
}


void CCP3_CaptureStart (void)
{
    CCP3CON1SET = _CCP3CON1_ON_MASK;
}


void CCP3_CaptureStop (void)
{
    CCP3CON1CLR = _CCP3CON1_ON_MASK;
}

uint16_t CCP3_Capture16bitBufferRead (void)
{
    return (uint16_t)CCP3BUF;
}


void CCP3_TimerCallbackRegister(CCP_TIMER_CALLBACK callback, uintptr_t context)
{
    ccp3TimerObj.callback_fn = callback;
    ccp3TimerObj.context = context;
}

void CCT3_InterruptHandler(void)
{
    uint32_t status = IFS2bits.CCT3IF;
    IFS2CLR = _IFS2_CCT3IF_MASK;    //Clear IRQ flag    
    if( (ccp3TimerObj.callback_fn != NULL))
    {
        ccp3TimerObj.callback_fn(status, ccp3TimerObj.context);
    }
}


void CCP3_CaptureCallbackRegister(CCP_CAPTURE_CALLBACK callback, uintptr_t context)
{
    ccp3CaptureObj.callback_fn = callback;
    ccp3CaptureObj.context = context;
}

void CCP3_InterruptHandler(void)
{
    IFS2CLR = _IFS2_CCP3IF_MASK;    //Clear IRQ flag
    if( (ccp3CaptureObj.callback_fn != NULL))
    {
        ccp3CaptureObj.callback_fn(ccp3CaptureObj.context);
    }
}


