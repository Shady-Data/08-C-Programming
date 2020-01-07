/*
* 
*  name: Robert Chunn
*  date: 06 Jan 2020
*  project: Demo Lab 2
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/02_Variables/07_Type_conversions.md
*/

#include <stdio.h>

int main(void)
{
    int integer = 44;
    float singlePrecision = 2.2;
    double doublePrecision = 3.1415926535897932;
    char singleChar = '$';
    char singleChar2 = 33;

    // printf("\n\n\nsize of integer is %ld \n", sizeof(integer));
    printf("\n\n\nValue of integer is %d \n", integer);
    printf("Value of integer as a float is %f \n", (float)integer);
    printf("Value of integer as a char is %c \n\n", (char)integer);
    // printf("size of float is %ld \n", sizeof(singlePrecision));
    printf("Value of float is %f \n", singlePrecision);
    printf("Value of float as a double is %f \n", (double)singlePrecision);
    // printf("size of double is %ld \n", sizeof(doublePrecision));
    printf("Value of double is %f \n", doublePrecision);
    printf("Value of double as a float is %f \n\n", (float)doublePrecision);
    // printf("size of char 1 is %ld \n", sizeof(singleChar));
    printf("Value of char 1 is %c \n", singleChar);
    printf("Value of char 1 as an integer is %d \n", (int)singleChar);
    // printf("size of char 2 is %ld \n\n\n", sizeof(singleChar2));
    printf("Value of %d as a char is %c\n", 63, (char)63);

    return 0;
}