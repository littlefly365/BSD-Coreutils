PROG=ls
SRCS=cmp.c ls.c main.c print.c util.c

LDADD= -lnutil

.if defined(NO_ACL)
CPPFLAGS += -D_NO_ACL
.else
LDADD += -lacl
.endif

CPPFLAGS += -D_XOPEN_SOURCE=700
SYMLINKS = dir vdir

.include "../../mk/prog.mk"
