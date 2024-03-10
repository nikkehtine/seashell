#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "repl.h"

const char PROMPT[3] = "$ ";
const int MAX = 256;

void repl_halt(bool *running, int *exit_code, int status_code)
{
    *running = false;
    *exit_code = status_code;
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

        if (strlen(buf) == 1 && isspace(buf[0]))
        {
            continue;
        }

        // Naive parsing
        char *command = strtok(buf, " ");
        if (command != NULL && strcmp(buf, "exit") == 0)
        {
            int arg_exit_code;
            char *arg0 = strtok(buf, " ");
            if (arg0 == NULL)
            {
                arg_exit_code = 0;
            }
            else
            {
                bool arg_is_not_num = false;
                for (size_t i = 0; i < strlen(arg0); i++)
                {
                    if (!isdigit(arg0[i]))
                    {
                        arg_is_not_num = true;
                        break;
                    }
                }

                int arg0_int;

                if (arg_is_not_num)
                {
                    arg0_int = atoi(arg0);
                }
                else
                {
                    arg0_int = 1;
                }
                arg_exit_code = arg0_int;
            }
            repl_halt(&running, &exit_code, arg_exit_code);
        }
        else if (command != NULL)
        {
            printf(">>> %s\n", command);
        }
    }

    return exit_code;
}
