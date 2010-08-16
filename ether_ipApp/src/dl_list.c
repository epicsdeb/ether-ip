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

#include "dl_list.h"

/* Remove head node from list (doesn't free node)
 * Returns 0 for empty list
 */
void *DLL_decap (DL_List *list)
{
    DLL_Node *node = list->first;
    if (! node)
        return 0;
    
    list->first = node->next;
    if (list->last == node)
        list->last = 0;
    return node;
}

