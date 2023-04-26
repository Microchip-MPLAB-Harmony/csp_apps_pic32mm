/*******************************************************************************
  Capture/Compare/PWM/Timer Module CCP2 Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ccp2.c

  Summary:
    CCP2 Source File

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
#include "plib_ccp2.h"
#include "interrupts.h"
// *****************************************************************************

// *****************************************************************************
// Section: CCP2 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

volatile static CCP_TIMER_OBJECT ccp2TimerObj;
void CCP2_CompareInitialize (void)
{
    /* Disable Timer */
    CCP2CON1CLR = _CCP2CON1_ON_MASK;

    CCP2CON1 = 0x3;

    CCP2CON2 = 0x8000000;

    CCP2CON3 = 0x0;

    CCP2PR = 4800;
    CCP2RA = 500;
    CCP2RB = 1000;

    IEC2SET = _IEC2_CCT2IE_MASK;
}

void CCP2_CompareStart (void)
{
    CCP2CON1SET = _CCP2CON1_ON_MASK;
}

void CCP2_CompareStop (void)
{
    CCP2CON1CLR = _CCP2CON1_ON_MASK;
}

void CCP2_CompareAutoShutdownClear (void)
{
    CCP2STATCLR = _CCP2STAT_ASEVT_MASK;
}

void CCP2_CompareAutoShutdownSet (void)
{
    CCP2CON2SET = _CCP2CON2_SSDG_MASK;
}

  
void CCP2_Compare16bitValueSet (uint16_t value)
{
    CCP2RA = (uint16_t)value;
}
uint16_t CCP2_Compare16bitValueGet (void)
{
    return (uint16_t)CCP2RA;
}

void CCP2_Compare16bitPeriodValueSet (uint16_t value)
{
    CCP2PR = value;
}

uint16_t CCP2_Compare16bitPeriodValueGet (void)
{
    return (uint16_t)CCP2PR;
}


void CCP2_CompareDeadTimeSet (uint8_t value)
{
    CCP2CON3 = (uint8_t)(value & (uint8_t)_CCP2CON3_DT_MASK);
}

uint8_t CCP2_CompareDeadTimeGet (void)
{
    return (uint8_t)(CCP2CON3 & _CCP2CON3_DT_MASK);
}

void CCP2_TimerCallbackRegister(CCP_TIMER_CALLBACK callback, uintptr_t context)
{
    ccp2TimerObj.callback_fn = callback;

    ccp2TimerObj.context = context;
}

void __attribute__((used)) CCT2_InterruptHandler (void)
{
    /* Additional local variable to prevent MISRA C violations (Rule 13.x) */
    uintptr_t context = ccp2TimerObj.context;
    uint32_t status = IFS2bits.CCT2IF;
    IFS2CLR = _IFS2_CCT2IF_MASK;    //Clear IRQ flag

    if( (ccp2TimerObj.callback_fn != NULL))
    {
        ccp2TimerObj.callback_fn(status, context);
    }
}

