/*      $NetBSD: stat.h,v 1.69 2019/09/15 23:55:22 christos Exp $       */

/*-
 * Copyright (c) 1982, 1986, 1989, 1993
 *      The Regents of the University of California.  All rights reserved.
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
 *
 *      @(#)stat.h      8.12 (Berkeley) 8/17/94
 */

#ifndef _SYS_NB_STAT_H
#define _SYS_NB_STAT_H

#include <string.h>
#include <sys/types.h>
#include <sys/vfs.h>

#define	S_ISTXT	0001000
#define	S_IFWHT  0160000
#define	S_ISWHT(m)	(((m) & S_IFMT) == S_IFWHT)

#ifndef __GLIBC__
#define	S_IFMT	 0170000
#endif

#define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#ifndef __GLIBC__
#define     ALLPERMS        (S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
#endif

int fchflags(int fd, unsigned long flags);
int chflags(const char *path, unsigned long flags);
int lutimens(const char *path, const struct timespec *times);
int utimens(const char *path, const struct timespec *times);
const char *devname(dev_t dev, mode_t type);



struct bsd_statfs {
    long f_type;
    char f_fstypename[32];
};

static const char *fsname_from_magic(long magic) {
    switch (magic) {
        case 0xEF53: return "ext2/3/4";
        case 0x01021994: return "tmpfs";
        default: return "unknown";
    }
}

static int bsd_statfs(const char *path, struct bsd_statfs *buf) {
    struct statfs s;

    if (statfs(path, &s) != 0)
        return -1;

    buf->f_type = s.f_type;
    strcpy(buf->f_fstypename, fsname_from_magic(s.f_type));
    return 0;
}

#define UF_SETTABLE     0x0000ffff      /* mask of owner changeable flags */
#define UF_NODUMP       0x00000001      /* do not dump file */
#define UF_IMMUTABLE    0x00000002      /* file may not be changed */
#define UF_APPEND       0x00000004      /* writes to file may only append */
#define UF_OPAQUE       0x00000008      /* directory is opaque wrt. union */

#define SF_SETTABLE     0xffff0000      /* mask of superuser changeable flags */
#define SF_ARCHIVED     0x00010000      /* file is archived */
#define SF_IMMUTABLE    0x00020000      /* file may not be changed */
#define SF_APPEND       0x00040000      /* writes to file may only append */
/*      SF_NOUNLINK     0x00100000         [NOT IMPLEMENTED] */
#define SF_SNAPSHOT     0x00200000      /* snapshot inode */
#define SF_LOG          0x00400000      /* WAPBL log file inode */
#define SF_SNAPINVAL    0x00800000      /* snapshot is invalid */


#define MNT_RDONLY      0x00000001      /* read only filesystem */
#define MNT_SYNCHRONOUS 0x00000002      /* file system written synchronously */
#define MNT_NOEXEC      0x00000004      /* can't exec from filesystem */
#define MNT_NOSUID      0x00000008      /* don't honor setuid bits on fs */
#define MNT_NODEV       0x00000010      /* don't interpret special files */
#define MNT_UNION       0x00000020      /* union with underlying filesystem */
#define MNT_ASYNC       0x00000040      /* file system written asynchronously */
#define MNT_NOCOREDUMP  0x00008000      /* don't write core dumps to this FS */
#define MNT_RELATIME    0x00020000      /* only update access time if mod/ch */
#define MNT_IGNORE      0x00100000      /* don't show entry in df */
#define MNT_NFS4ACLS    0x00200000      /* uses NFS4 Access Control Lists */
#define MNT_DISCARD     0x00800000      /* use DISCARD/TRIM if supported */
#define MNT_EXTATTR     0x01000000      /* enable extended attributes */
#define MNT_LOG         0x02000000      /* Use logging */
#define MNT_NOATIME     0x04000000      /* Never update access times in fs */
#define MNT_AUTOMOUNTED 0x10000000      /* mounted by automountd(8) */
#define MNT_SYMPERM     0x20000000      /* recognize symlink permission */
#define MNT_NODEVMTIME  0x40000000      /* Never update mod times for devs */
#define MNT_SOFTDEP     0x80000000      /* Use soft dependencies */
#define MNT_POSIX1EACLS 0x00000800      /* shared with EXKERB */
#define MNT_ACLS        MNT_POSIX1EACLS /* synonym */

#define MNT_WAIT        1       /* synchronously wait for I/O to complete */
#define MNT_NOWAIT      2       /* start all I/O, but do not wait for it */

#define	MNAMELEN	90	

#endif
