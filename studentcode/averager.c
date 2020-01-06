#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv){
    double a, b, c;

    printf("Enter the first number :");
    scanf("%lf", &a);

    printf("Enter the second number :");
    scanf("%lf", &b);

    printf("Enter the third number :");
    scanf("%lf", &c);

    double average = (a + b + c) / 3.0; // all ints in the problem will result in a int converted to a double (all 0s after the decimal) needs one float for precision

    printf("The average of %f, %f, and %f is %f\n", a, b, c, average);

    return 0;
}