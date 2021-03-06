/*
 * Copyright (c) 2011-2012 LeafGrass <leafgrass.g@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 */

/*
 * @file    core/sys_time.c
 * @brief   system time related routines
 * @log     2011.8 initial revision
 */

#include <ousia/ousia_type.h>
#include <port/ousia_port.h>
#include <sys/print.h>
#include <sys/sync.h>
#include <sys/time.h>
#include <sys/sched.h>

static uint32 __systime = 0;

static void __systick_interrupt(void);

/*
 * @brief   os systick interrupt handler
 * @param   none
 * @return  none
 * @note    none
 */
static void __systick_interrupt(void)
{
	os_enter_critical();
	__systime++;
	_sched_systick_call();
	os_exit_critical();
	return;
}

/*
 * @brief   system timetick init
 * @param   none
 * @return  none
 * @note    none
 */
void _sys_time_systick_init(void)
{
	__systime = 0UL;
	port_systick_init(&__systick_interrupt);
}

/*
 * @brief   get system time
 * @param   none
 * @return  32 bit integer value for time
 * @note    none
 */
uint32 os_systime_get(void)
{
	return __systime;
}
