
#ifndef _LOWLEVEL_H
#define _LOWLEVEL_H

#include "secbool.h"

void periph_init(void);
uint32_t flash_wait_and_clear_status_flags(void);
secbool flash_check_option_bytes(void);
void flash_lock_option_bytes(void);
void flash_unlock_option_bytes(void);
uint32_t flash_set_option_bytes(void);
secbool flash_configure_option_bytes(void);
secbool reset_flags_check(void);

#endif // BOARDLOADER_LOWLEVEL_H
