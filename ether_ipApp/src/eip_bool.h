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

#ifndef EIP_BOOL_H_
#define EIP_BOOL_H_

/* Andrew Johnson (ANL) found an issue with bool/true/false
 * and a PPC604-with-Altivec compiler, so we use eip_bool
 * and are careful not to redefine 'true'.
 */
typedef int eip_bool;
#ifndef __cplusplus
  #ifndef true
    #define true  1
    #define false 0
  #endif
#endif

#endif /*EIP_BOOL_H_*/
