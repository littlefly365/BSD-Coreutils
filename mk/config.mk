TOP ?= ..
TOPTREE ?= $(TOP)/$(TOP)
CC ?= clang

LIBPATH =-L$(TOP)/libcompat -L$(TOP)/libutil -L$(TOP)/libacl
LCFLAGS ?=
LLDFLAGS ?=

CFLAGS ?= -O2 
CPPFLAGS +=-I$(TOPTREE)/include
LDFLAGS += $(LIBPATH)
MAKEFLAGS += -j$(nproc)
LDADD ?=
LDLIBS += $(LDADD) -lcompat

DESTDIR ?= 
PREFIX ?= usr/local
LIBDIR ?= $(PREFIX)/lib

.SILENT:
