.include "config.mk"

.if defined(PROG)
SRCS ?= ${PROG}.c
OBJS ?= ${SRCS:.c=.o}
.else
PROG = ${SCRIPT:.sh=}
OBJS = ${SCRIPT:.sh=}
.endif

all: prog

prog: ${OBJS}
	@echo "---${PROG}---"
.if defined(SCRIPT)
	chmod +x ${PROG}
.else
	$(CC) ${OBJS} ${LDFLAGS} ${LDLIBS} -o ${PROG}
.endif
.c.o:
.if defined(SCRIPT)
	@cp ${SCRIPT} ${PROG}
.else
	@${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@ 
.endif
clean:
	@rm -rf ${PROG} ${OBJS}
install:
	@install -D -m 755 ${PROG} ${DESTDIR}/${BINT}/${PROG} >/dev/null

.if defined(SYMLINKS)
.for s in ${SYMLINKS}
	@ln -sf ${PROG} ${DESTDIR}/${BINT}/${s}
.endfor
.endif

.PHONY: all prog clean install
