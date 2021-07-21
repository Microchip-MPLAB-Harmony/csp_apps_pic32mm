/*******************************************************************************
  Capture/Compare/PWM/Timer Module (CCP1) Peripheral Library (PLIB)

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

// *****************************************************************************

// *****************************************************************************
// Section: CCP1 Implementation
// *****************************************************************************
// *****************************************************************************

void CCP1_CaptureInitialize (void)
{
    /* Disable Timer */
    CCP1CON1CLR = _CCP1CON1_ON_MASK;

    CCP1CON1 = 0x13;

    CCP1CON2 = 0x0;

    CCP1CON3 = 0x0;

}


void CCP1_CaptureStart (void)
{
    CCP1CON1SET = _CCP1CON1_ON_MASK;
}


void CCP1_CaptureStop (void)
{
    CCP1CON1CLR = _CCP1CON1_ON_MASK;
}

uint16_t CCP1_Capture16bitBufferRead (void)
{
    return (uint16_t)CCP1BUF;
}



bool CCP1_CaptureStatusGet (void)
{
    bool status = false;
    status = ((CCP1STAT >> _CCP1STAT_ICBNE_POSITION) & _CCP1STAT_ICBNE_MASK);
    return status;
}

