/*******************************************************************************
  Capture/Compare/PWM/Timer Module CCP1 Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ccp1.c

  Summary:
    CCP1 Source File

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
#include "plib_ccp1.h"
#include "interrupts.h"
// *****************************************************************************

// *****************************************************************************
// Section: CCP1 Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

void CCP1_CompareInitialize (void)
{
    /* Disable Timer */
    CCP1CON1CLR = _CCP1CON1_ON_MASK;

    CCP1CON1 = 0x4;

    CCP1CON2 = 0x1000000;

    CCP1CON3 = 0x0;

    CCP1PR = 4800;
    CCP1RA = 520;
    CCP1RB = 1000;

}

void CCP1_CompareStart (void)
{
    CCP1CON1SET = _CCP1CON1_ON_MASK;
}

void CCP1_CompareStop (void)
{
    CCP1CON1CLR = _CCP1CON1_ON_MASK;
}

void CCP1_CompareAutoShutdownClear (void)
{
    CCP1STATCLR = _CCP1STAT_ASEVT_MASK;
}

void CCP1_CompareAutoShutdownSet (void)
{
    CCP1CON2SET = _CCP1CON2_SSDG_MASK;
}


  

void CCP1_Compare16bitPeriodValueSet (uint16_t value)
{
    CCP1PR = value;
}

uint16_t CCP1_Compare16bitPeriodValueGet (void)
{
    return (uint16_t)CCP1PR;
}


void CCP1_Compare16bitRAValueSet (uint16_t value)
{
    CCP1RA = value;
}

uint16_t CCP1_Compare16bitRAValueGet (void)
{
    return (uint16_t)CCP1RA;
}

void CCP1_Compare16bitRBValueSet (uint16_t value)
{
    CCP1RB = value;
}

uint16_t CCP1_Compare16bitRBValueGet (void)
{
    return (uint16_t)CCP1RB;
}

void CCP1_CompareDeadTimeSet (uint8_t value)
{
    CCP1CON3 = (uint8_t)(value & (uint8_t)_CCP1CON3_DT_MASK);
}

uint8_t CCP1_CompareDeadTimeGet (void)
{
    return (uint8_t)(CCP1CON3 & _CCP1CON3_DT_MASK);
}


