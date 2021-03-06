/*
* 
*  name: Robert Chunn
*  date: 21 Jan 2020
*  project: Performance Lab 24
* 
*/

#include <stdio.h>
#include <string.h>

// define a concatenation macro
#define CONCAT_FOR_REAL(x, y) x##y
#define CONCAT(x, y) CONCAT_FOR_REAL(x, y)
// #define CONCAT(x, y) x##y
// define a macro to stringify (wrap in quotes)
#define STRING_WRAP_FOR_REAL(a) #a
#define STRING_WRAP(b) STRING_WRAP_FOR_REAL(b) // STRING_WRAP() requires 2 MACROS (one to call itself) to allow the expansion of the CONCAT() MACRO before the "#" stringifies the entire CONCAT() MACRO call
// #define STRING_WRAP(a) #a
// define a constant buffersize for an array
#define BUFFSIZE 64

int main(void)
{
    // define an array with a dimension of BUFFSIZE and intialized with the result of the STRING_WRAP() and CONCAT() MACROs
    char myArray [BUFFSIZE] = STRING_WRAP(CONCAT(Preprocesso, CONCAT(r checkin, CONCAT(g if define, CONCAT(d MACRO, s are working)))));
    puts(myArray);
    // printf("%s : %ld\n", myArray, strlen(myArray));


    return 0;
}