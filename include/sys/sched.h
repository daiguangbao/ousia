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
 * @file    include/sys/sched.h
 * @brief   header of implementation of ousia scheduler
 * @log     2011.7 initial revision
 */

#ifndef __SYS_SCHED_H__
#define __SYS_SCHED_H__

/*
 * process state
 * FIXME need an exact requirement for each state
 */
enum _pstate {
	/*PSTAT_BLOCK  = -1,*/
	PSTAT_SLEEP = 0,
	PSTAT_RUN   = 1,
	PSTAT_READY = 2
};

/*
 * process control block
 */
struct _pcb_t {
	void *stack_ptr;
	void (*pentry)(void *args);
	uint32 stack_size;
	uint32 pid;
	int32 prio;
	enum _pstate stat;
	struct _ptcb_t *timer;
	struct _pcb_t *p_prev;
	struct _pcb_t *p_next;
};

/*
 * process queue control block
 */
struct _pqcb_t {
	uint32 pnum;
	struct _pcb_t *p_head;
	struct _pcb_t *p_tail;
};

os_status _sys_sched_init(uint32 strategy);
os_status _sys_sched_schedule(void);


#endif /* __SYS_SCHED_H__ */
