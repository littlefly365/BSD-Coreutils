.include "config.mk"

SRCS ?= ${PROG}.c
OBJS ?= ${SRCS:.c=.o}

all: prog

prog: ${OBJS}
	@echo "---${PROG}---"
	@$(CC) ${OBJS} ${LDFLAGS} ${LDLIBS} -o ${PROG}
.c.o:
	@${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@ >/dev/null
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
