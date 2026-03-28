#include <errno.h>
#include <unistd.h>

int 
fchflags(int fd, unsigned long flags)
{
    return -1;
}

int 
chflags(const char *path, unsigned long flags)
{
    return -1;
}
