IMPDIR = libcompat libutil

SUBDIR=	arch base64 basename cat chmod chown chroot comm cp csplit cut date dd df \
	dirname du echo env expand expr factor false fmt fold head hexdump hostid hostname id install 	\
	join kill link ln logname ls mkdir mkfifo mknod mktemp mv nice nl nohup nproc paste 	\
	pathchk printenv printf pwd realpath renice rm rmdir seq sleep sort split stat 	stty	\
	sync tail tee test timeout touch tr true truncate tsort tty uname unexpand uniq \
	unlink users wc who yes

.if defined(NO_ACL)
CPPFLAGS += -D_NO_ACL
.endif

.if !defined(NO_LIBMD)
SUBDIR+=cksum
.endif

.include "../mk/subdir.mk"
