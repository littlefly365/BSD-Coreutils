.if defined(IMPDIR)
ALL_TARGET=important
.else
ALL_TARGET= 
.endif

all: ${ALL_TARGET}

.for dir in ${SUBDIR}
	@echo "===> ${dir}"
	@${MAKE} -C ${dir}
.endfor

clean:
.for dir in ${SUBDIR}
	@echo "===> ${dir}"
	@${MAKE} -C ${dir} clean
.endfor

install:
.for dir in ${SUBDIR}
	@echo "===> ${dir}"
	@${MAKE} -C ${dir} install
.endfor

important:
.if defined(IMPDIR)
.for dir in ${IMPDIR}
	@echo "===> ${dir}"
	@${MAKE} -C ${dir}
.endfor
.endif

.PHONY: all clean install important
