#include <stdio.h>

int main(void)
{
    int x = 7;

    printf("x++ %d; ++x %d\n", x++, ++x);
    x = 7;
    printf("++x %d; x++ %d\n", ++x, x++);

    return 0;
}