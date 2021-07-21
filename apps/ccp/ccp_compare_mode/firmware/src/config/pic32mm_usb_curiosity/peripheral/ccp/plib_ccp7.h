/*******************************************************************************
  Capture/Compare/PWM/Timer Module (CCP) Peripheral Library Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ccp7.h

  Summary:
    CCP PLIB Header File

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

#ifndef _PLIB_CCP7_H
#define _PLIB_CCP7_H

#include <stddef.h>
#include <stdint.h>
#include "device.h"
#include "plib_ccp_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END


// *****************************************************************************
// Section: Interface
// *****************************************************************************
// *****************************************************************************

/*************************** CCP7 API ****************************************/
// *****************************************************************************
/* Function:
   void CCP7_CompareInitialize (void)

  Summary:
    Initialization function CCP7 peripheral

  Description:
    This function initializes the CCP7 peripheral with user input
	from the configurator.

  Parameters:
    void

  Returns:
    void
*/
void CCP7_CompareInitialize (void);

// *****************************************************************************
/* Function:
   void CCP7_CompareStart (void)

  Summary:
    Enable function CCP7 peripheral

  Description:
    This function enables the CCP7 peripheral

  Parameters:
    void

  Returns:
    void
*/
void CCP7_CompareStart (void);

// *****************************************************************************
/* Function:
   void CCP7_CompareStop (void)

  Summary:
    Disable function CCP7 peripheral

  Description:
    This function disables the CCP7 peripheral.

  Parameters:
    void

  Returns:
    void
*/
void CCP7_CompareStop (void);

void CCP7_CompareAutoShutdownClear (void);

void CCP7_CompareAutoShutdownSet (void);


void CCP7_Compare16bitValueSet (uint16_t value);

uint16_t CCP7_Compare16bitValueGet (void);

void CCP7_Compare16bitPeriodValueSet (uint16_t value);

uint16_t CCP7_Compare16bitPeriodValueGet (void);



// *****************************************************************************
/* Function:
  void CCP7_TimerCallbackRegister( CCP_TIMER_CALLBACK callback, uintptr_t context )

  Summary:
    Sets the callback function for a ocmp interrupt.

  Description:
    This function sets the callback function that will be called when the timer overflows.

  Precondition:
    None.

  Parameters:
    *callback   - a pointer to the function to be called when value is reached.
                  Use NULL to Un Register the timer callback

    context     - a pointer to user defined data to be used when the callback
                  function is called. NULL can be passed in if no data needed.

  Returns:
    void
*/
void CCP7_TimerCallbackRegister(CCP_TIMER_CALLBACK callback, uintptr_t context);

// *****************************************************************************
/* Function:
  void CCP7_CompareCallbackRegister( CCP_COMPARE_CALLBACK callback, uintptr_t context )

  Summary:
    Sets the callback function for a ocmp interrupt.

  Description:
    This function sets the callback function that will be called when the compare match occurs.

  Precondition:
    None.

  Parameters:
    *callback   - a pointer to the function to be called when value is reached.
                  Use NULL to Un Register the compare callback

    context     - a pointer to user defined data to be used when the callback
                  function is called. NULL can be passed in if no data needed.

  Returns:
    void
*/
void CCP7_CompareCallbackRegister(CCP_COMPARE_CALLBACK callback, uintptr_t context);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif

// DOM-IGNORE-END
#endif // _PLIB_CCP7_H
