/*******************************************************************************
  Capture/Compare/PWM/Timer Module CCP4 Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ccp4.c

  Summary:
    CCP4 Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2025 Microchip Technology Inc. and its subsidiaries.
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
#include "plib_ccp4.h"
#include "interrupts.h"
// *****************************************************************************

// *****************************************************************************
// Section: CCP4 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

static volatile CCP_TIMER_OBJECT ccp4TimerObj;
void CCP4_CompareInitialize (void)
{
    /* Disable Timer */
    CCP4CON1 &= ~_CCP4CON1_ON_MASK;

    CCP4CON1 = 0x1;

    CCP4CON2 = 0x1000000;

    CCP4CON3 = 0x0;

    CCP4PR = 4000;
    CCP4RA = 500;
    CCP4RB = 1000;

    IEC2 |= _IEC2_CCT4IE_MASK;
}

void CCP4_CompareStart (void)
{
    CCP4CON1 |= _CCP4CON1_ON_MASK;
}

void CCP4_CompareStop (void)
{
    CCP4CON1 &= ~_CCP4CON1_ON_MASK;
}

void CCP4_CompareAutoShutdownClear (void)
{
    CCP4STAT &= ~_CCP4STAT_ASEVT_MASK;
}

void CCP4_CompareAutoShutdownSet (void)
{
    CCP4CON2 |= _CCP4CON2_SSDG_MASK;
}

  
void CCP4_Compare16bitValueSet (uint16_t value)
{
    CCP4RA = (uint16_t)value;
}
uint16_t CCP4_Compare16bitValueGet (void)
{
    return (uint16_t)CCP4RA;
}

void CCP4_Compare16bitPeriodValueSet (uint16_t value)
{
    CCP4PR = value;
}

uint16_t CCP4_Compare16bitPeriodValueGet (void)
{
    return (uint16_t)CCP4PR;
}



void CCP4_TimerCallbackRegister(CCP_TIMER_CALLBACK callback, uintptr_t context)
{
    ccp4TimerObj.callback_fn = callback;

    ccp4TimerObj.context = context;
}

void __attribute__((used)) CCT4_InterruptHandler (void)
{
    /* Additional local variable to prevent MISRA C violations (Rule 13.x) */
    uintptr_t context = ccp4TimerObj.context;
    uint32_t status = IFS2bits.CCT4IF;
    IFS2 &= ~_IFS2_CCT4IF_MASK;    //Clear IRQ flag

    if( (ccp4TimerObj.callback_fn != NULL))
    {
        ccp4TimerObj.callback_fn(status, context);
    }
}

