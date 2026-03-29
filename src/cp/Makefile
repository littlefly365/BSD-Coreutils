PROG=cp
SRCS=cp.c utils.c

.if defined(NO_ACL)
CPPFLAGS += -D_NO_ACL -DSMALL
.else
LDADD += -lacl 
.endif

.include "../../mk/prog.mk"
