#include <stdio.h>
#include <stdlib.h>
#include_next <grp.h>

static char 
*group_from_gid(gid_t gid, int nogroup)
{
    struct group *gr;

    gr = getgrgid(gid);
    if (gr)
        return gr->gr_name;

    static char buf[32];
    snprintf(buf, sizeof(buf), "%u", (unsigned)gid);
    return buf;
}

static int
gid_from_group(const char *name, gid_t *gid)
{
    struct group *gr;

    gr = getgrnam(name);
    if (gr) {
        *gid = gr->gr_gid;
        return 0;
    }

    char *end;
    long val = strtol(name, &end, 10);

    if (*end == '\0') {
        *gid = (gid_t)val;
        return 0;
    }

    return -1;
}

static inline int
pwcache_groupdb(int (*a)(int), void (*b)(void), struct group *(*c)(const char *), struct group *(*d)(gid_t))
{
        return 0;
}
