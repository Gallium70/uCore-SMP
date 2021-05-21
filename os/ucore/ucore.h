#if !defined(UCORE_H)
#define UCORE_H

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) ); })

#include <ucore/types.h>
#include <arch/cpu.h>
#include <ucore/defs.h>
#include <utils/log.h>
#include <arch/riscv.h>
#include <utils/assert.h>
#include <utils/trace.h>
#endif // UCORE_H
