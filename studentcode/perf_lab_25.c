/*
* 
*  name: Robert Chunn
*  date: 21 Jan 2020
*  project: Performance Lab 25
* 
*/

#include <stdio.h>

// define an "in release" specifier for an if defined check for compilation
#ifndef release
#define release "in release"
#endif

// define the _INC_STDIO specifier for an if defined check for compilation
#ifndef _INC_STDIO
#define _INC_STDIO 1
#endif

// redefine EOF to 66
#ifdef EOF
#undef EOF
#endif
#define EOF 66

// compile if in "release" && _INC_STDIO defined
#if defined(release) && defined(_INC_STDIO)
#define PRINT_MACRO(x) printf(#x " is %d\n", x) // MACRO to print a MACRO and it's value

int main()
{
    // if FOPEN_MAX, FILENAME_MAX, and EOF are defined
    #if defined(FOPEN_MAX) && defined(FILENAME_MAX) && defined(EOF)
    PRINT_MACRO(FOPEN_MAX); // print the MACRO and it's value
    PRINT_MACRO(FILENAME_MAX);
    PRINT_MACRO(EOF);
    #else
    // otherwise print that the expected MACROs were not defined
    printf("Expected MACROs were not found to be defined!\n");
    #endif

    return 0;
}
#endif