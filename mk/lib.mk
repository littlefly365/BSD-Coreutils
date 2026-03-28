.include "config.mk"

OBJS ?= $(SRCS:.c=.o)

all: $(LIB) $(OBJS)

$(LIB): 
	@echo "---lib$(LIB)---"
	@echo "$(CC) $(OBJS) -o lib$(LIB).a"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $(SRCS)
	@$(AR) rcs lib$(LIB).a $(OBJS)
clean:
	rm -rf lib$(LIB).a $(OBJS)
install:
	 install -D -m 755 lib$(LIB).a $(DESTDIR)/$(LIBDIR)/lib$(LIB).a
.PHONY: all $(LIB)

