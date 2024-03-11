#ifndef PARSE_H
#define PARSE_H

typedef enum
{
    ERR_TOO_MANY_ARGS,
    ERR_ARG_TOO_LONG,
} ParserErrorType;

typedef struct
{
    ParserErrorType type;
    char message[100];
} ParserError;

void parse_args(char **buffer) {}

#endif
