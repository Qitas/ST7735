
//#include STM32_HAL_H
#include <stdlib.h>
#include "common.h"
#include "display.h"
//#include "rng.h"

void shutdown(void);

#define COLOR_FATAL_ERROR RGB16(0x7F, 0x00, 0x00)

void __attribute__((noreturn)) __fatal_error(const char *expr, const char *msg, const char *file, int line, const char *func) {
//    display_orientation(0);
//    display_backlight(255);
//    display_print_color(COLOR_WHITE, COLOR_FATAL_ERROR);
//    printf("\nFATAL ERROR:\n");
//    if (expr) {
//        printf("expr: %s\n", expr);
//    }
//    if (msg) {
//        printf("msg : %s\n", msg);
//    }
//    if (file) {
//        printf("file: %s:%d\n", file, line);
//    }
//    if (func) {
//        printf("func: %s\n", func);
//    }
//#ifdef GITREV
//    printf("rev : %s\n", XSTR(GITREV));
//#endif
    //shutdown();
    for (;;);
}

#ifndef NDEBUG
void __assert_func(const char *file, int line, const char *func, const char *expr) {
    __fatal_error(expr, "assert failed", file, line, func);
}
#endif

void hal_delay(uint32_t ms)
{
    //HAL_Delay(ms);
}

//uint32_t __stack_chk_guard = 0;

//void __attribute__((noreturn)) __stack_chk_fail(void)
//{
//    ensure(secfalse, "Stack smashing detected");
//}
