
#ifndef _SECBOOL_H
#define _SECBOOL_H

#include <stdint.h>

typedef uint32_t secbool;
#define sectrue  0xAAAAAAAAU
#define secfalse 0x00000000U

#ifndef __wur
#define __wur __attribute__ ((warn_unused_result))
#endif

#endif
