#ifndef _NB_PWD_H
#define _NB_PWD_H

#include <stdio.h>
#include <stdlib.h>
#include_next <pwd.h>

static char *user_from_uid(uid_t uid, int nouser) 
{ 
    struct passwd *pw;

    pw = getpwuid(uid);
    if (pw)
        return pw->pw_name;

    static char buf[32];
    snprintf(buf, sizeof(buf), "%u", (unsigned)uid);
    return buf;
}

static int
uid_from_user(const char *name, uid_t *uid)
{
    struct passwd *pw;

    pw = getpwnam(name);
    if (pw) {
        *uid = pw->pw_uid;
        return 0;
    }

    char *end;
    long val = strtol(name, &end, 10);

    if (*end == '\0') {
        *uid = (uid_t)val;
        return 0;
    }

    return -1;
}

static inline int undelete(const char *path) { return 0; }

static inline int
pwcache_userdb(int (*a)(int), void (*b)(void), struct passwd *(c)(const char *), struct passwd *(*d)(uid_t))
{
        return 0;
}

#define      _PASSWORD_LEN           128

#endif
