#include <sys/acl.h>

long
lpathconf(const char *path, int name)
{
	(void)path;
	(void)name;
	return -1;
}

int fcpxattr(int from_fd, int to_fd)
{
	return 1;
}
