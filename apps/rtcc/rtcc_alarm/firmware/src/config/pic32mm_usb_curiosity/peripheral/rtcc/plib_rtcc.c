/*******************************************************************************
  Real Time Counter (RTCC) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_rtcc.c

  Summary:
    RTCC PLIB Implementation file

  Description:
    This file defines the interface to the RTC peripheral library. This
    library provides access to and control of the associated peripheral
    instance in clock/calendar mode.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2ONE9 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_rtcc.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

#define decimaltobcd(x)                 (((x / 10) << 4) + ((x - ((x / 10) * 10))))
#define bcdtodecimal(x)                 ((x & 0xF0) >> 4) * 10 + (x & 0x0F)

/* Real Time Clock System Service Object */
typedef struct _SYS_RTCC_OBJ_STRUCT
{
    /* Call back function for RTCC.*/
    RTCC_CALLBACK  callback;

    /* Client data (Event Context) that will be passed to callback */
    uintptr_t context;

} RTCC_OBJECT;

static RTCC_OBJECT rtcc;

// *****************************************************************************
// *****************************************************************************
// Section: RTCC Implementation
// *****************************************************************************
// *****************************************************************************

void RTCC_Initialize( void )
{
    /* Unlock System */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    RTCCON1CLR = _RTCCON1_WRLOCK_MASK;  /* Enable writes to RTCC */

    /* Lock System */
    SYSKEY = 0x00000000;
    RTCCON1CLR = _RTCCON1_RTCOE_MASK;  /* Disable RTCC output */

    /* Set RTCC clock configuration */
    RTCCON2 = 0x3fff0001;


    RTCCON1SET = _RTCCON1_CHIME_MASK;  /* Set alarm to repeat forever */


    /* start the RTC */
    RTCCON1SET = _RTCCON1_ON_MASK;
}

void RTCC_InterruptEnable( RTCC_INT_MASK interrupt )
{
    IEC1SET = interrupt;
}

void RTCC_InterruptDisable( RTCC_INT_MASK interrupt )
{
    IEC1CLR = interrupt;
}

bool RTCC_TimeSet( struct tm *Time )
{
    uint32_t timeField = 0, dateField = 0;

    timeField = (decimaltobcd(Time->tm_hour) << _RTCTIME_HRONE_POSITION) & (_RTCTIME_HRTEN_MASK | _RTCTIME_HRONE_MASK);
    timeField |= (decimaltobcd(Time->tm_min) << _RTCTIME_MINONE_POSITION) & (_RTCTIME_MINTEN_MASK | _RTCTIME_MINONE_MASK);
    timeField |= (decimaltobcd(Time->tm_sec) << _RTCTIME_SECONE_POSITION) & (_RTCTIME_SECTEN_MASK | _RTCTIME_SECONE_MASK);

    while((RTCSTAT & _RTCSTAT_SYNC_MASK) != 0);

    RTCTIME = timeField;

    dateField = (decimaltobcd(Time->tm_year % 100) << _RTCDATE_YRONE_POSITION) & (_RTCDATE_YRONE_MASK | _RTCDATE_YRTEN_MASK);
    dateField |= (decimaltobcd((Time->tm_mon + 1)) << _RTCDATE_MTHONE_POSITION)&(_RTCDATE_MTHONE_MASK | _RTCDATE_MTHTEN_MASK);
    dateField |= (decimaltobcd(Time->tm_mday) << _RTCDATE_DAYONE_POSITION) & (_RTCDATE_DAYONE_MASK | _RTCDATE_DAYTEN_MASK);
    dateField |= decimaltobcd(Time->tm_wday) & _RTCDATE_WDAY_MASK;

    while((RTCSTAT & _RTCSTAT_SYNC_MASK) != 0);

    RTCDATE = dateField;

    RTCCON1SET = _RTCCON1_ON_MASK;  /* Start the RTCC module */

    return true;    /* This PLIB has no way of indicating wrong device operation so always return true */
}

void RTCC_TimeGet( struct tm  *Time )
{
    uint32_t dataTime, dataDate;

    while((RTCSTAT & _RTCSTAT_SYNC_MASK) != 0);

    dataTime = RTCTIME;  /* read the time from the RTC */

    Time->tm_hour = 10 * (bcdtodecimal((dataTime & _RTCTIME_HRTEN_MASK) >> _RTCTIME_HRTEN_POSITION)) +
                         bcdtodecimal((dataTime & _RTCTIME_HRONE_MASK) >> _RTCTIME_HRONE_POSITION);
    Time->tm_min =  10 * (bcdtodecimal((dataTime & _RTCTIME_MINTEN_MASK) >> _RTCTIME_MINTEN_POSITION)) +
                         bcdtodecimal((dataTime & _RTCTIME_MINONE_MASK) >> _RTCTIME_MINONE_POSITION);
    Time->tm_sec =  10 * (bcdtodecimal((dataTime & _RTCTIME_SECTEN_MASK) >> _RTCTIME_SECTEN_POSITION)) +
                         bcdtodecimal((dataTime & _RTCTIME_SECONE_MASK) >> _RTCTIME_SECONE_POSITION);

    while((RTCSTAT & _RTCSTAT_SYNC_MASK) != 0);

    dataDate = RTCDATE;  /* read the date from the RTC */

    Time->tm_year = 10 * (bcdtodecimal((dataDate & _RTCDATE_YRTEN_MASK) >> _RTCDATE_YRTEN_POSITION)) +
                         bcdtodecimal((dataDate & _RTCDATE_YRONE_MASK) >> _RTCDATE_YRONE_POSITION);
    Time->tm_year += 2000;  /* This RTC designed for 0-99 year range.  Need to add 2000 to that. */
    Time->tm_mon = (10 * (bcdtodecimal((dataDate & _RTCDATE_MTHTEN_MASK) >> _RTCDATE_MTHTEN_POSITION)) +
                         bcdtodecimal((dataDate & _RTCDATE_MTHONE_MASK) >> _RTCDATE_MTHONE_POSITION)) - 1;
    Time->tm_mday = 10 * (bcdtodecimal((dataDate & _RTCDATE_DAYTEN_MASK) >> _RTCDATE_DAYTEN_POSITION)) +
                         bcdtodecimal((dataDate & _RTCDATE_DAYONE_MASK) >> _RTCDATE_DAYONE_POSITION);

    Time->tm_wday = bcdtodecimal((dataDate & _RTCDATE_WDAY_MASK) >> _RTCDATE_WDAY_POSITION);
    Time->tm_yday = 0;  /* not used */
    Time->tm_isdst = 0;    /* not used */
}

bool RTCC_AlarmSet( struct tm *alarmTime, RTCC_ALARM_MASK alarmFreq )
{
    uint32_t dataDate, dataTime;

    /* Disable interrupt, if enabled, before setting up alarm */
    RTCC_InterruptDisable(RTCC_INT_ALARM);

    RTCCON1CLR = _RTCCON1_ALRMEN_MASK;  /* Disable alarm */
    while(RTCSTATbits.ALMSYNC);  /* Wait for disable */

    if(RTCC_ALARM_MASK_OFF != alarmFreq)
    {
        dataDate  = (decimaltobcd((alarmTime->tm_mon + 1)) << _RTCDATE_MTHONE_POSITION) & (_RTCDATE_MTHONE_MASK | _RTCDATE_MTHTEN_MASK);
        dataDate |= (decimaltobcd(alarmTime->tm_mday) << _RTCDATE_DAYONE_POSITION) & (_RTCDATE_DAYONE_MASK | _RTCDATE_DAYTEN_MASK);
        dataDate |= decimaltobcd(alarmTime->tm_wday) & _RTCDATE_WDAY_MASK;

        dataTime  = (decimaltobcd(alarmTime->tm_hour) << _RTCTIME_HRONE_POSITION) & (_RTCTIME_HRTEN_MASK | _RTCTIME_HRONE_MASK);
        dataTime |= (decimaltobcd(alarmTime->tm_min) << _RTCTIME_MINONE_POSITION) & (_RTCTIME_MINTEN_MASK | _RTCTIME_MINONE_MASK);
        dataTime |= (decimaltobcd(alarmTime->tm_sec) << _RTCTIME_SECONE_POSITION) & (_RTCTIME_SECTEN_MASK | _RTCTIME_SECONE_MASK);

        while((RTCSTAT & _RTCSTAT_SYNC_MASK) != 0);

        ALMDATE = dataDate;

        while((RTCSTAT & _RTCSTAT_SYNC_MASK) != 0);

        ALMTIME = dataTime;

        /* Configure alarm repetition */
        RTCCON1bits.AMASK = alarmFreq;

        /* ALRMEN = 1 */
        RTCCON1SET = _RTCCON1_ALRMEN_MASK;  /* Enable the alarm */
    }

    RTCC_InterruptEnable(RTCC_INT_ALARM);  /* Enable the interrupt to the interrupt controller */

    return true;  /* This PLIB has no way of indicating wrong device operation so always return true */
}

void RTCC_CallbackRegister( RTCC_CALLBACK callback, uintptr_t context )
{
    rtcc.callback = callback;

    rtcc.context = context;
}

void RTCC_InterruptHandler( void )
{
    /* Clear the status flag */
    IFS1CLR = 0x1;

    if(rtcc.callback != NULL)
    {
        rtcc.callback(rtcc.context);
    }
}

