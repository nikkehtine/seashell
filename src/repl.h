#include <stdbool.h>

#ifndef REPL_H
#define REPL_H

void repl_halt(bool *running, int *exit_code);

int repl(void);

#endif
