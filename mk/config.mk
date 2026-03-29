TOP ?= ..
CC ?= clang

LIBPATH =-L$(TOP)/libcompat -L$(TOP)/libutil
LCFLAGS ?=
LLDFLAGS ?=

CFLAGS ?= -O2 
CPPFLAGS +=-I$(TOP)/include
LDFLAGS += $(LIBPATH)
MAKEFLAGS += -j$(nproc)
LDADD ?=
LDLIBS += $(LDADD) -lcompat

DESTDIR ?= 
PREFIX ?= usr/local
LIBDIR ?= $(PREFIX)/lib

ACL ?= yes

.export ACL

.SILENT:
