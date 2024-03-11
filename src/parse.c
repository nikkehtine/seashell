#include <stdbool.h>
#include <stdio.h>

#include "parse.h"

const int MAX_TOKEN = 100;
const int MAX_TOKEN_L = 256;

ParserError parse_args(char **buffer)
{
    char token[MAX_TOKEN_L];
    char args[MAX_TOKEN][sizeof token];

    int i = 0;
    buffer[strcspn(buffer, "\n")] = 0;

    char *current_token = strtok(buffer, " ");
    while (token != NULL)
    {
        if (strlen(current_token) < sizeof token)
        {
            strcpy(args[i], current_token);
            ++i;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        *current_token = strtok(NULL, " ");
    }

    struct ParserError err;
    err.type = NULL;
}
