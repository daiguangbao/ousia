/* *****************************************************************************
 * @file    include/ousia/ousia_type.h
 *
 * @brief   micro implementation of stdarg.h of libc
 *
 * @log     2011.9 initial revision
 *
 * *****************************************************************************
 * COPYRIGHT (C) LEAFGRASS - LeafGrass (leafgrass.g@gmail.com)
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 * ****************************************************************************/

#ifndef __OUSIA_TYPE_H__
#define __OUSIA_TYPE_H__

#include <port/ousia_cfg.h>

#ifdef OUSIA_USE_LIBMAPLE
#include <stm32/libmaple/libmaple_types.h>
#else
typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int16;
typedef unsigned short uint16;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;
#endif /* OUSIA_USE_LIBMAPLE */
typedef enum {
        FALSE = 0, TRUE  = !FALSE
} bool;

typedef enum _os_status
{
        OS_ERR = -1,
        OS_OK = 0
} os_status;


#endif /* __OUSIA_TYPE_H__ */

