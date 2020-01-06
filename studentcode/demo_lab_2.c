#include <stdio.h>

int main(void)
{
    int integer = 1;
    float singlePrecision = 2.2;
    double doublePrecision = 3.3;
    char singleChar = '$';
    char singleChar2 = 33;

    printf("\n\n\nsize of integer is %ld \n", sizeof(integer));
    printf("size of float is %ld \n", sizeof(singlePrecision));
    printf("size of double is %ld \n", sizeof(doublePrecision));
    printf("size of char 1 is %ld \n", sizeof(singleChar));
    printf("size of char 2 is %ld \n\n\n", sizeof(singleChar2));

    return 0;
}