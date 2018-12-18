

#ifndef _RNG_H
#define _RNG_H

#include <stdint.h>

void rng_init(void);
uint32_t rng_read(const uint32_t previous, const uint32_t compare_previous);
uint32_t rng_get(void);

#endif
