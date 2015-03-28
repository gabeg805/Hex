// 
// CONTRIBUTORS: 
// 
//     * Gabriel Gonzalez (gabeg@bu.edu) 
// 
// 
// LICENSE: 
// 
//     The MIT License (MIT)
// 
// 
// NAME:
// 
//     hex.c - Print input in its decimal, hexadecimal, and binary interpretation.
// 
// 
// SYNTAX: 
// 
//     hex [-h|--help] [[-dec] [-hex] <value>]
// 
// 
// PURPOSE:
// 
//     Takes the input value and prints the decimal, hex, and binary form of the 
//     value.
// 
// 
// KEYWORDS:
// 
//     -h, --help 
//         Print program usage.
// 
//     -dc, --dec
//         Treat input value as a decimal value. 
// 
//     -hx, --hex
//         Treat input value as a hex value.
// 
//     <value>
//         Input value to convert.
// 
// 
// FUNCTIONS:
// 
//     print_usage - Print program usage.
// 
//     strtohex    - Convert input string into literal hexadecimal.
// 
//     print_dec   - Print the decimal interpretation of the input string.
//     print_hex   - Print the hexadecimal interpretation of the input string.
//     print_bin   - Print the binary interpretation of the input string.
// 
// 
// FILE STRUCTURE:
// 
//     * Print Program Usage
//     * Value Conversion
//     * Print Value
//     * Display Value In Decimal, Hex, and Binary
// 
// 
// MODIFICATION HISTORY:
// 	
//     gabeg Nov 25 2014 <> Created.
//     
//     gabeg Nov 30 2014 <> Added comments and functions to make code look cleaner. 
//                          Also implemented the hex conversions, before only decimal 
//                          was working.
// 
//     gabeg Jan 14 2015 <> Updated the documentation for the program.
//     
//     gabeg Mar 27 2015 <> Changed layout of code and added a function to parse 
//                          command line arguments.
//     
// **********************************************************************************



// =====================
// INCLUDES AND DECLARES
// =====================

// Includes
#include "../hdr/hex.h"



// ///////////////////////////////
// ///// PRINT PROGRAM USAGE /////
// ///////////////////////////////

// Print program usage
void print_usage() {
    printf("%s\n", "Usage: hex [-h|--help] [[-dec] [-hex] <value>]");
}



// ///////////////////////
// ///// PRINT VALUE /////
// ///////////////////////

// Print integer in decimal format
void print_dec(long long dec) {
    printf("Decimal: %lld\n", dec);
}



// Print integer in hex format
void print_hex(long long hex) {
    printf("Hex:\t 0x%llx\n", hex);
}



// Print integer in binary format
void print_bin(long long bin) {
    long long val;
    short count = 32;
    short index = 0;
    char flag = 0;
    char chunk[5] = {'0', '0', '0', '0', 0};
    
    printf("Binary:\t ");
    while ( count >= 0 ) {
        val = (bin >> (count-1)) & 0x1;
        
        if ( index == 4 ) {
            if ( flag || strcmp(chunk, "0000") ) {
                printf("%s ", chunk);
                flag = 1;
            }
            index = 0;
        }
        
        chunk[index] = val+'0';
        ++index;
        --count;
    }
    
    printf("\n");
}



// ////////////////////////////////////////
// ///// PARSE COMMAND LINE ARGUMENTS /////
// ////////////////////////////////////////

// Parse the command line arguments
int cli_arg_parse(int argc, char **argv) {
    int i = 0;
    
    while ( i < argc ) {
        if ( (strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0) )
            return 0;
        
        if ( strcmp(argv[i], "-dec") == 0 )
            return 1;
        
        if ( strcmp(argv[i], "-hex") == 0 )
            return 2;
        
        ++i;
    }
    
    printf("Error: Invalid arguments.\n");
    
    return 0;
}



// ////////////////////////////
// ///// VALUE CONVERSION /////
// ////////////////////////////

// Convert input string into literal hexadecimal
long long strtohex(char *str) {
    
    // Initialize variables
    int i, sub,
        start = 0,
        len = strlen(str);
    long long ret = 0;
    
    // Set values according to string length 
    if ( len == 1 )
        return str[0];
    else if ( len > 2 ) 
        if ( (str[0] == '0') && ( (str[1] == 'x') || (str[1] == 'X') ) )
            start = 2;
    
    // Loop through string chars
    for ( i = start; i < len; ++i ) {
        if ( str[i] >= 'a' )
            sub = 'a' - 10;
        else if ( str[i] >= 'A' )
            sub = 'A' - 10;
        else
            sub = '0';
        
        ret = (ret << 4) + str[i] - sub;
    }
    
    return ret;
}



// /////////////////////////////////////////////////////
// ///// DISPLAY VALUE IN DECIMAL, HEX, AND BINARY /////
// /////////////////////////////////////////////////////

// Convert value to decimal, hex, and binary and print result
int main(int argc, char **argv) {
    
    // Parse command line arguments
    int convert = cli_arg_parse(argc, argv);
    
    // Determine input value
    long long num = 0;
    
    switch ( convert ) {
    case 1:
        num = strtohex(argv[2]);
        break;
    case 2: 
        num = atoll(argv[2]);
        break;
    default:
        print_usage();
        return 1;
    }
    
    // Print value conversions
    print_dec(num);
    print_hex(num);
    print_bin(num);
    
    return 0;
}
