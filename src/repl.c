#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "repl.h"

const char PROMPT[3] = "$ ";
const int MAX = 256;

void repl_halt(bool *running, int *exit_code, int status_code)
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
        printf("%s", PROMPT);
        char buf[MAX];
        fgets(buf, MAX, stdin);
        if (strlen(buf) == 1 && buf[0] == 10)
        {
            continue;
        }
        else
        {
            repl_halt(&running, &exit_code, 0);
        }
    }

    return exit_code;
}
