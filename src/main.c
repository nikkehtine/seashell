#include <stdio.h>

#include "repl.h"

int main(int argc, char **argv)
{
    printf("Hello world!\n");

    int exit_code = repl();

    return exit_code;
}
