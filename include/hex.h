/* *****************************************************************************
 * 
 * Name:    hex.h
 * Author:  Gabriel Gonzalez
 * Email:   gabeg@bu.edu
 * License: The MIT License (MIT)
 * 
 * Syntax: None.
 * 
 * Description: Print input value in the corresponding decimal, hexadecimal, and
 *              binary interpretations.
 * 
 * Notes: None.
 * 
 * *****************************************************************************
 */

/* Header guard */
#ifndef HEX_H
#define HEX_H

/* Includes */
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <getopt.h>
#include <unistd.h>

/* Defines */
#define PROGRAM   "hex"
#define WORD_SIZE 16

#if WORD_SIZE == 8
#define INTWORD_T int8_t
#elif WORD_SIZE == 16
#define INTWORD_T int16_t
#elif WORD_SIZE == 32
#define INTWORD_T int32_t
#elif WORD_SIZE == 64
#define INTWORD_T int64_t
#else
#define INTWORD_T int32_t
#endif

/* Typedefs */
typedef INTWORD_T intw_t;

#undef INTWORD_T

#endif /* HEX_H */
