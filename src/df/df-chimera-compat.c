/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1980, 1990, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <err.h>
#include <mntent.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include "df.h"

int
getmntinfo(struct mntinfo **mntbuf)
{
    struct mntinfo *list = NULL;
    struct mntinfo *cur;
    struct mntent *ent;
    struct statvfs sv;
    struct stat st;
    FILE *fp;
    int n = 0;

    fp = setmntent("/proc/self/mounts", "r");
    if (fp == NULL)
        err(1, "setmntent");

    while ((ent = getmntent(fp)) != NULL) {

        if (hasmntopt(ent, MNTTYPE_IGNORE))
            continue;

        if (vfslist_l || vfslist_t) {
            if (checkvfsselected(ent->mnt_type) != 0)
                continue;
        }

        if (statvfs(ent->mnt_dir, &sv) == -1)
            continue;

        if (stat(ent->mnt_dir, &st) == -1)
            continue;

        list = realloc(list, (n + 1) * sizeof(*list));
        if (!list)
            err(1, "realloc");

        cur = &list[n];

        memset(cur, 0, sizeof(*cur));

        cur->f_fstypename = strdup(ent->mnt_type);
        cur->f_mntfromname = strdup(ent->mnt_fsname);
        cur->f_mntonname = strdup(ent->mnt_dir);
        cur->f_opts = strdup(ent->mnt_opts);

        cur->f_blocks = sv.f_blocks;
        cur->f_bfree  = sv.f_bfree;
        cur->f_bavail = sv.f_bavail;
        cur->f_files  = sv.f_files;
        cur->f_ffree  = sv.f_ffree;
        cur->f_bsize  = sv.f_bsize;
        cur->f_frsize = sv.f_frsize;
        cur->f_flag   = sv.f_flag;
        cur->f_namemax = sv.f_namemax;

        /* stat */
        cur->f_dev = st.st_dev;

        cur->f_selected = 1;

        n++;
    }

    endmntent(fp);

    *mntbuf = list;
    return n;
}

int
checkvfsname(const char *vfsname, const char **vfslist, int skip)
{

	if (vfslist == NULL)
		return (0);
	while (*vfslist != NULL) {
		if (strcmp(vfsname, *vfslist) == 0)
			return (skip);
		++vfslist;
	}
	return (!skip);
}

int
checkvfsselected(char *fstypename)
{
	int result;

	if (vfslist_t) {
		/* if -t option used then select passed types */
		result = checkvfsname(fstypename, vfslist_t, skipvfs_t);
		if (vfslist_l) {
			/* if -l option then adjust selection */
			if (checkvfsname(fstypename, vfslist_l, skipvfs_l) == skipvfs_t)
				result = skipvfs_t;
		}
	} else {
		/* no -t option then -l decides */
		result = checkvfsname(fstypename, vfslist_l, skipvfs_l);
	}
	return (result);
}
