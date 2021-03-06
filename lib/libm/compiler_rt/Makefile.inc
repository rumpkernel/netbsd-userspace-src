# $NetBSD: Makefile.inc,v 1.5 2014/02/26 22:37:56 joerg Exp $

COMPILER_RT_SRCDIR=	${NETBSDSRCDIR}/sys/external/bsd/compiler_rt/dist

.if ${MACHINE_ARCH} == "powerpc"
COMPILER_RT_CPU_DIR=	${COMPILER_RT_SRCDIR}/lib/builtins/ppc
COMPILER_RT_ARCH_DIR=	${COMPILER_RT_SRCDIR}/lib/builtins/ppc
.else
COMPILER_RT_CPU_DIR=	${COMPILER_RT_SRCDIR}/lib/builtins/${MACHINE_CPU}
COMPILER_RT_ARCH_DIR=	${COMPILER_RT_SRCDIR}/lib/builtins/${MACHINE_ARCH}
.endif

.PATH: ${COMPILER_RT_CPU_DIR}
.PATH: ${COMPILER_RT_ARCH_DIR}
.PATH: ${COMPILER_RT_SRCDIR}/lib/builtins

# Needs scaling support
GENERIC_SRCS+= \
	mulxc3.c \
	mulsc3.c \
	divxc3.c \
	divdc3.c \
	divsc3.c

.for src in ${GENERIC_SRCS}
.  if exists(${COMPILER_RT_CPU_DIR}/${src:R}.S) || \
      exists(${COMPILER_RT_ARCH_DIR}/${src:R}.S)
SRCS+=	${src:R}.S
.  else
SRCS+=	${src}
.    if ${HAVE_GCC:U} != "4"
COPTS.${src}+=	-Wno-error=missing-prototypes
.    else
COPTS.${src}+=	-Wno-missing-prototypes
.    endif
.  endif
.endfor
