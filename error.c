// File: error.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 2.8.2023
// Compiled: gcc version 11.3.0

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

// prints an error message and possible arguments to the stderr
void warning_msg(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

// works in the same way as 'warning_msg' but in the end terminates the program with 'exit(1)'
void error_exit(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}