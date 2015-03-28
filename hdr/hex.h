// Header guard
#ifndef HEX_H
#define HEX_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Public functions
void print_usage();
void print_dec(long long dec);
void print_hex(long long hex);
void print_bin(long long bin);
int cli_arg_parse(int argc, char **argv);
long long strtohex(char *str);

#endif
