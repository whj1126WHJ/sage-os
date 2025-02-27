#include <common.h>

static void os_init() {
  pmm->init();
}

static void os_run() {
#ifndef TEST
  for (const char *s = "Hello World from CPU #*\n"; *s; s++) {
    putch(*s == '*' ? '0' + cpu_current() : *s);
  }
  while (1)
    ;
#else  // for unit test
  printf("Hello World from CPU #%d\n", cpu_current());
  halt(0);  // must halt at here, not in unit test
#endif
}

MODULE_DEF(os) = {
    .init = os_init,
    .run  = os_run,
};
