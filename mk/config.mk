TOP ?= ..
CC ?= clang

LIBPATH =-L$(TOP)/libnetbsd -L$(TOP)/libutil
LCFLAGS ?=
LLDFLAGS ?=

CFLAGS ?= -O2 
CPPFLAGS +=-I$(TOP)/include
LDFLAGS += $(LIBPATH)
MAKEFLAGS += -j$(nproc)
LDADD ?=
LDLIBS += $(LDADD) -lnetbsd

DESTDIR ?= 
PREFIX ?= usr/local
LIBDIR ?= $(PREFIX)/lib
INCDIR ?= $(PREFIX)/include/netbsd/

#.SILENT:
