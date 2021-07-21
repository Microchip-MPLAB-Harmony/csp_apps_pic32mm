/*******************************************************************************
  CCP Peripheral Library Interface Source File

  Company
    Microchip Technology Inc.

  File Name
    plib_ccp5.c

  Summary
    CCP5 peripheral library source file.

  Description
    This file implements the interface to the CCP peripheral library.  This
    library provides access to and control of the associated peripheral
    instance.

*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include "plib_ccp5.h"



void CCP5_TimerInitialize(void)
{
    /* Disable Timer */
    CCP5CON1CLR = _CCP5CON1_ON_MASK;

    CCP5CON1 = 0x0;

    CCP5CON2 = 0x0;

    CCP5CON3 = 0x0;

    /* Clear counter */
    CCP5TMR = 0x0;

    /*Set period */
    CCP5PR = 7199U;


}


void CCP5_TimerStart(void)
{
    CCP5CON1SET = _CCP5CON1_ON_MASK;
}


void CCP5_TimerStop (void)
{
    CCP5CON1CLR = _CCP5CON1_ON_MASK;
}

void CCP5_Timer16bitPeriodSet(uint16_t period)
{
    CCP5PR  = period;
}

uint16_t CCP5_Timer16bitPeriodGet(void)
{
    return (uint16_t)CCP5PR;
}

uint16_t CCP5_Timer16bitCounterGet(void)
{
    return (uint16_t)(CCP5TMR);
}


uint32_t CCP5_TimerFrequencyGet(void)
{
    return (24000000);
}

