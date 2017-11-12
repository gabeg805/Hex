/* *****************************************************************************
 * 
 * Name:    hex.c
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Syntax: hex [-h] [-H] [-D] [-B] <value>
 * 
 * Description: Print input value in the corresponding decimal, hexadecimal, and
 *              binary interpretations.
 * 
 * Notes: None.
 * 
 * *****************************************************************************
 */

/* Includes */
#include "hex.h"

/* Private functions */
static void   usage(void);
static intw_t strtodec(char *str);
static intw_t strtohex(char *str);
static intw_t strtobin(char *str);
static void   printdec(intw_t value);
static void   printhex(intw_t value);
static void   printbin(intw_t value);

/* ************************************************************************** */
/* Main */
int main(int argc, char **argv)
{
    /* Check if no arguments given */
    if (argc == 1) {
        usage();
        exit(0);
    }

    /* Command line options */
    const char    *shortopts  = "hD:H:B:";
    struct option  longopts[] = {
        {"help", no_argument,       0,  'h' },
        {"dec",  required_argument, 0,  'D' },
        {"hex",  required_argument, 0,  'H' },
        {"bin",  required_argument, 0,  'B' },
        {0,      0,                 0,   0  }
    };

    /* Options */
    bool   decimal = false;
    bool   hex     = false;
    bool   binary  = false;
    intw_t value;

    /* Parse options */
    int opt;

    while ((opt=getopt_long(argc, argv, shortopts, longopts, NULL)) != -1)
    {
        switch (opt) {
        case 'h':
            usage();
            exit(0);
        case 'D':
            decimal = true;
            value   = strtodec(optarg);
            break;
        case 'H':
            hex   = true;
            value = strtohex(optarg);
            break;
        case 'B':
            binary = true;
            value  = strtobin(optarg);
            break;
        default:
            usage(); 
            exit(1);
        }
    }

    /* Check only 1 argument specified */
    char argcheck = decimal + hex + binary;

    if (!argcheck) {
        fprintf(stderr, "%s: Invalid option(s) entered.\n", PROGRAM);
        exit(1);
    }

    if (argcheck > 1) {
        fprintf(stderr, "%s: Too many options entered.\n", PROGRAM);
        exit(1);
    }

    /* Run entered option */
    printdec(value);
    printhex(value);
    printbin(value);

    return 0;
}

/* ************************************************************************** */
/* Print program usage */
void usage(void)
{
    printf("Usage: hex [options] <args>\n");
    printf("\n");
    printf("Options:\n");
    printf("    -h, --help\n");
    printf("        Print program usage.\n");
    printf("\n");
    printf("    -D, --dec <value>\n");
    printf("        Input is treated as a decimal value. Print decimal, hex,\n");
    printf("        and binary representation.\n");
    printf("\n");
    printf("    -H, --hex <value>\n");
    printf("        Input is treated as a hex value. Print decimal, hex, and\n");
    printf("        binary representation.\n");
    printf("\n");
    printf("Arguments:\n");
    printf("    <value>\n");
    printf("        An integer or hex value.\n");
}

/* ************************************************************************** */
/* Convert string to decimal value */
intw_t strtodec(char *str)
{
    intw_t dec;

#if WORD_SIZE == 8
    dec = atoi(str);
#elif WORD_SIZE == 16
    dec = atoi(str);
#elif WORD_SIZE == 32
    dec = atoi(str);
#elif WORD_SIZE == 64
    dec = atol(str);
#else
    dec = atoi(str);
#endif

    return (strcmp(str, "")) ? dec : -1;
}

/* ************************************************************************** */
/* Convert input string into literal hexadecimal */
intw_t strtohex(char *str)
{
    intw_t hex   = 0;
    size_t start = 0;
    char   s[]   = {str[1], 0};

    /* Check string */
    if (!strcmp(str, "")) {
        return -1;
    }


    if ((str[0] == '0') && !strcasecmp(s, "x")) {
        start = 2;
    }

    /* Convert string */
    char c;
    char v;
    int  i;

    for (i=start; str[i]; i++) {
        c = tolower(str[i]);

        if ((c >= '0') && (c <= '9')) {
            v = c - '0';
        }
        else if ((c >= 'a') && (c <= 'f')) {
            v = c - ('a' - 10);
        }
        else {
            return -1;
        }

        hex = (hex << 4) + v;
    }

    return hex;
}

/* ************************************************************************** */
/* Convert input string into binary form */
intw_t strtobin(char *str)
{
    /* Check string */
    if (!strcmp(str, "")) {
        return -1;
    }

    /* Convert string */
    intw_t binary = 0;
    int    shift  = strlen(str);
    int    i;

    for (i=0; shift > 0; shift--, i++)
    {
        switch (str[i]) {
        case '1':
            binary += (1 << (shift-1));
            break;
        case '0':
            break;
        case ' ':
            binary >>= 1;
            break;
        default:
            return -1;
        }
    }

    return binary;
}

/* ************************************************************************** */
/* Print integer in decimal format */
void printdec(intw_t value)
{
#if WORD_SIZE == 8
#define FORMAT "%d"
#elif WORD_SIZE == 16
#define FORMAT "%d"
#elif WORD_SIZE == 32
#define FORMAT "%d"
#elif WORD_SIZE == 64
#define FORMAT "%ld"
#else
#define FORMAT "%d"
#endif

    printf("%-8s: " FORMAT "\n", "Decimal", value);

#undef FORMAT
}

/* ************************************************************************** */
/* Print integer in hex format */
void printhex(intw_t value)
{
#if WORD_SIZE == 8
#define FORMAT "%x"
#elif WORD_SIZE == 16
#define FORMAT "%x"
#elif WORD_SIZE == 32
#define FORMAT "%x"
#elif WORD_SIZE == 64
#define FORMAT "%lx"
#else
#define FORMAT "%d"
#endif

    printf("%-8s: 0x" FORMAT "\n", "Hex", value);

#undef FORMAT
}

/* ************************************************************************** */
/* Print integer in binary format */
void printbin(intw_t value)
{
    char binary[5] = {'0', '0', '0', '0', 0};
    char bit;
    bool flag;
    int  size;
    int  i;

    printf("%-8s: ", "Binary");

    /* Print binary string (ignoring leading 0's) */
    for (i=0, size=WORD_SIZE, flag=false; size >= 0; size--, i++) {
        bit = (value >> (size-1)) & 0x1;

        if ((i%4) == 0) {
            if (flag || strcmp(binary, "0000")) {
                printf("%s ", binary);
                flag = true;
            }
        }

        binary[i%4] = bit+'0';
    }

    printf("\n");
}
