/*******************************************************************************
  Capture/Compare/PWM/Timer Module CCP7 Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ccp7.c

  Summary:
    CCP7 Source File

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
#include "plib_ccp7.h"

// *****************************************************************************

// *****************************************************************************
// Section: CCP7 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

static CCP_TIMER_OBJECT ccp7TimerObj;
static CCP_COMPARE_OBJECT ccp7CompareObj;
void CCP7_CompareInitialize (void)
{
    /* Disable Timer */
    CCP7CON1CLR = _CCP7CON1_ON_MASK;

    CCP7CON1 = 0x1;

    CCP7CON2 = 0x0;

    CCP7CON3 = 0x0;

    CCP7PR = 4000;
    CCP7RA = 500;
    CCP7RB = 1000;

    IEC2SET = _IEC2_CCT7IE_MASK;
    /* Enable input compare interrupt */
    IEC2SET = _IEC2_CCP7IE_MASK;
}

void CCP7_CompareStart (void)
{
    CCP7CON1SET = _CCP7CON1_ON_MASK;
}

void CCP7_CompareStop (void)
{
    CCP7CON1CLR = _CCP7CON1_ON_MASK;
}

void CCP7_CompareAutoShutdownClear (void)
{
    CCP7STATCLR = _CCP7STAT_ASEVT_MASK;
}

void CCP7_CompareAutoShutdownSet (void)
{
    CCP7CON2SET = _CCP7CON2_SSDG_MASK;
}

  
void CCP7_Compare16bitValueSet (uint16_t value)
{
    CCP7RA = (uint16_t)value;
}
uint16_t CCP7_Compare16bitValueGet (void)
{
    return (uint16_t)CCP7RA;
}

void CCP7_Compare16bitPeriodValueSet (uint16_t value)
{
    CCP7PR = value;
}

uint16_t CCP7_Compare16bitPeriodValueGet (void)
{
    return (uint16_t)CCP7PR;
}



void CCP7_TimerCallbackRegister(CCP_TIMER_CALLBACK callback, uintptr_t context)
{
    ccp7TimerObj.callback_fn = callback;

    ccp7TimerObj.context = context;
}

void CCT7_InterruptHandler (void)
{
    uint32_t status = IFS2bits.CCT7IF;
    IFS2CLR = _IFS2_CCT7IF_MASK;    //Clear IRQ flag

    if( (ccp7TimerObj.callback_fn != NULL))
    {
        ccp7TimerObj.callback_fn(status, ccp7TimerObj.context);
    }
}

void CCP7_CompareCallbackRegister(CCP_COMPARE_CALLBACK callback, uintptr_t context)
{
    ccp7CompareObj.callback_fn = callback;
    ccp7CompareObj.context = context;
}

void CCP7_InterruptHandler(void)
{
    uint32_t status = IFS2bits.CCP7IF;
    IFS2CLR = _IFS2_CCP7IF_MASK;    //Clear IRQ flag
    if( (ccp7CompareObj.callback_fn != NULL))
    {
        ccp7CompareObj.callback_fn(status, ccp7CompareObj.context);
    }
}
