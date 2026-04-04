PROG=dd
SRCS=args.c conv.c conv_tab.c dd.c dd_hostops.c dd_swab.c misc.c position.c

CFLAGS += -DNO_CONV -DNO_MSGFMT -DNO_IOFLAG -include stdint.h
LDADD += -lnutil
.include "../../mk/prog.mk"
