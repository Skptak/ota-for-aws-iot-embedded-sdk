/*
 * AWS IoT Over-the-air Update v3.4.0
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file Posix_OtaStartTimer_harness.c
 * @brief Implements the proof harness for Posix_OtaStartTimer function.
 */
/*  POSIX includes for OTA library. */
#include "ota_os_posix.h"
#include <stdlib.h>

void OtaCallback( OtaTimerId_t otaTimerId )
{
}

/* Stub to create new per-process timer using CLOCK_ID.  */
int timer_create( clockid_t __clock_id,
                  struct sigevent * __restrict __evp,
                  timer_t * __restrict __timerid )
{
    int timerStatus;

    return timerStatus;
}

void Posix_OtaStartTimer_harness()
{
    OtaTimerId_t otaTimerId;
    const char * pTimerName;
    const uint32_t timeout;
    OtaTimerCallback_t callback;
    size_t size;

    /* The range of values for OtaTimerId_t enum is [0,2). */
    __CPROVER_assume( otaTimerId >= 0 && otaTimerId < 2 );

    /* Initialize to a callback timer. */
    callback = OtaCallback;

    pTimerName = ( char * ) malloc( size * sizeof( char ) );

    Posix_OtaStartTimer( otaTimerId, pTimerName, timeout, callback );

    free( pTimerName );
}
