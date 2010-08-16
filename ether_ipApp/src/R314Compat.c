/*************************************************************************\
* Copyright (c) 2001 - 2004 The Regents of the University of California,
*     as Operator of Los Alamos National Laboratory.
* Copyright (c) 2004 - 2009  Oak Ridge National Laboratory,
*     Oak Ridge, Tennessee 37831, U.S.A
* All rights reserved. Subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

/*
 *  Original Author: Kay-Uwe Kasemir <kasemirk@ornl.gov>,
 *  RTEMS/OSI Port : Stephanie Allison <saa@slac.stanford.edu>
 */

#include <sysLib.h>
#include <tickLib.h>
#include "R314Compat.h"

void epicsTimeGetCurrent(epicsTimeStamp *s)
{
    *s = tickGet();
}

double epicsTimeDiffInSeconds(epicsTimeStamp *B, epicsTimeStamp *A)
{   /* ULONG epicsTimeStamp ! */
    if (*B >= *A)
        return ((double)(*B - *A)) / sysClkRateGet();
    return -(((double)(*A - *B)) / sysClkRateGet());
}

int epicsTimeLessThan(epicsTimeStamp *A, epicsTimeStamp *B)
{
    return *A < *B;
}

int epicsTimeLessThanEqual(epicsTimeStamp *A, epicsTimeStamp *B)
{
    return *A <= *B;
}

void epicsTimeAddSeconds(epicsTimeStamp *T, double secs)
{
    *T += secs * sysClkRateGet();
}

double epicsThreadSleepQuantum()
{
    return 1.0/sysClkRateGet();
}

void epicsThreadSleep(double secs)
{
    taskDelay((int)(secs * sysClkRateGet()));
}
