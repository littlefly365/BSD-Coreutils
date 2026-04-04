#ifndef _SYS_ACL_H
#define _SYS_ACL_H

#include_next <sys/acl.h>

static inline acl_t acl_get_fd_np(int fd, acl_type_t _type)
{
        (void)_type;
        return acl_get_fd(fd);
}

#endif
