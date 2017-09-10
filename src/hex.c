/* *****************************************************************************
 * 
 * Name:    NAME
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Syntax: hex [option] <arg>
 * 
 * Description: Print input in its decimal, hexadecimal, and binary 
 *              interpretations.
 * 
 * Notes: NOTES
 * 
 * *****************************************************************************
 */

/* Includes */
#include "hex.h"

/* Defines */
#define PROG "hex"

/* Private functions */
static void usage(void);
static void printdec(long long value);
static void printhex(long long value);
static void printbin(long long value);
static long long strtohex(char *str);

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
    const char *shortopts = "hD:H:";
    struct option longopts[] = {
        {"help", no_argument,       0,  'h' },
        {"dec",  required_argument, 0,  'D' },
        {"hex",  required_argument, 0,  'H' },
        {0,      0,                 0,   0  }
    };

    /* Options */
    bool      decimal = false;
    bool      hex     = false;
    long long value;

    /* Parse options */
    int index = 0;
    int opt;

    while ((opt=getopt_long(argc, argv, shortopts, longopts, &index)) != -1)
    {
        switch (opt) {
        case 'h':
            usage();
            exit(0);
        case 'D':
            decimal = true;
            value   = atoll(optarg);
            break;
        case 'H':
            hex   = true;
            value = strtohex(optarg);
            break;
        default:
            usage(); 
            exit(1);
        }
    }

    /* Check arguments */
    unsigned short argcheck = decimal + hex;
    if (argcheck > 1) {
        fprintf(stderr, "%s: Too many options entered.\n", PROG);
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
static void usage(void)
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
/* Print integer in decimal format */
static void printdec(long long value)
{
    printf("%-8s: %lld\n", "Decimal", value);
}

/* ************************************************************************** */
/* Print integer in hex format */
static void printhex(long long value)
{
    printf("%-8s: 0x%llx\n", "Hex", value);
}

/* ************************************************************************** */
/* Print integer in binary format */
static void printbin(long long value)
{
    long long binval;
    char  binstr[5] = {'0', '0', '0', '0', 0};
    char  flag = 0;
    short word = 32;
    short i    = 0;

    printf("%-8s: ", "Binary");
    while (word >= 0) {
        binval = (value >> (word-1)) & 0x1;

        if ((i%4) == 0) {
            if (flag || strcmp(binstr, "0000")) {
                printf("%s ", binstr);
                flag = 1;
            }
        }

        binstr[i%4] = binval+'0';
        ++i;
        --word;
    }

    printf("\n");
}

/* ************************************************************************** */
/* Convert input string into literal hexadecimal */
static long long strtohex(char *str)
{
    size_t len   = strlen(str);
    size_t start = 0;

    /* Set string starting point based on string length */
    switch (len) {
    case 0:
        return 0LL;
    case 1: 
        return (long long) str[0];
    default:
        if ((str[0] == '0') && ((str[1] == 'x') || (str[1] == 'X')))
            start = 2;
        break;
    }

    long long hex = 0;
    int sub;
    int i;

    /* Loop through string chars */
    for (i=start; i < len; ++i) {
        if ( str[i] >= 'a' )
            sub = 'a' - 10;
        else if ( str[i] >= 'A' )
            sub = 'A' - 10;
        else
            sub = '0';
        hex = (hex << 4) + str[i] - sub;
    }

    return hex;
}
