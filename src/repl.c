#include <stdbool.h>
#include <stdio.h>

#include "repl.h"

const char PROMPT[] = "$ ";

void repl_halt(bool *running, int *exit_code)
{
    *running = false;
    *exit_code = 0;
}

int repl(void)
{
    bool running = true;
    int exit_code = 0;

    while (running)
    {
        printf("%s\n", PROMPT);
        repl_halt(&running, &exit_code);
    }

    return exit_code;
}
