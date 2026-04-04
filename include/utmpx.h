/*      $NetBSD: utmpx.h,v 1.18 2021/08/15 00:36:11 gutteridge Exp $     */

/*-
 * Copyright (c) 2002 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NB_UTMPX_H
#define _NB_UTMPX_H

#define _UTX_HOSTSIZE        	256
#define _UTX_USERSIZE   	32
#define _UTX_LINESIZE   	32
#define _UTX_IDSIZE     	4
#define _PATH_UTMPX             "/var/run/utmp"

#define _UTX_USERSIZE   32
#define _UTX_LINESIZE   32
#define _UTX_IDSIZE     4
#define _UTX_HOSTSIZE   256

#define UTX_USERSIZE    _UTX_USERSIZE
#define UTX_LINESIZE    _UTX_LINESIZE
#define UTX_IDSIZE      _UTX_IDSIZE
#define UTX_HOSTSIZE    _UTX_HOSTSIZE

#ifdef _LP64
#define _UTX_PADSIZE 36
#else
#define _UTX_PADSIZE 40
#endif

#define EMPTY           0
#define RUN_LVL         1
#define BOOT_TIME       2
#define INIT_PROCESS    5
#define LOGIN_PROCESS   6
#define USER_PROCESS    7
#define DEAD_PROCESS    8
#define ACCOUNTING      9
#define SIGNATURE       10
#define DOWN_TIME       11

void endutxent(void);
int utmpxname(const char *fname);
extern void setutxent (void);
extern struct utmpx *getutxent (void);
#define pututxline(x)

struct utmpx {
        char ut_name[_UTX_USERSIZE];    /* login name */
        char ut_id[_UTX_IDSIZE];        /* inittab id */
        char ut_line[_UTX_LINESIZE];    /* tty name */
        char ut_host[_UTX_HOSTSIZE];    /* host name */
        uint16_t ut_session;            /* session id used for windowing */
        uint16_t ut_type;               /* type of this entry */
        pid_t ut_pid;                   /* process id creating the entry */
        struct {
                uint16_t e_termination; /* process termination signal */
                uint16_t e_exit;        /* process exit status */
        } ut_exit;
        struct timeval ut_tv;           /* time entry was created */
        uint8_t ut_pad[_UTX_PADSIZE];   /* reserved for future use */
};

#endif

