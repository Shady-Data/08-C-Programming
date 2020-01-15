/*
* PERFORMANCE LAB 20.1
* (Rounding Numbers) Function floor may be used to round a number to a specific decimal place.
* The statement rounds x to the tenths position (the first position to the right of the decimal point).
* y = floor(x * 10 + .5) /10;
* The statement rounds x to the hundredths position (the second position to the right of the decimal point).
* y = floor(x * 10 + .5) /100;
* Write a program that defines four functions to round a number x in various ways:
* roundToInteger( number )
* roundToTenths( number )
* roundToHundreths( number )
* roundToThousandths( number )
*/

#include <stdio.h>
#include <math.h>

int roundToInteger(double x)
{
    return floor(x + .5);    
}
double roundToTenths(double x)
{
    return floor(x * 10 + .5)/10;    
}
double roundToHundreths(double x)
{
    return floor(x * 100 + .5)/100;    
}
double roundToThousandths(double x)
{
    return floor(x * 1000 + .5)/1000;    
}

void main()
{
    printf("5.66666 Round To Integer: %d\n", roundToInteger(5.66666));
    printf("4.21212 Round To Integer: %d\n", roundToInteger(4.21212));
    printf("5.66666 Round To Tenths: %f\n", roundToTenths(5.66666));
    printf("5.66666 Round To Tenths: %f\n", roundToTenths(5.66666));
    printf("5.66666 Round To Hundreths: %f\n", roundToHundreths(5.66666));
    printf("5.66666 Round To Hundreths: %f\n", roundToHundreths(5.66666));
    printf("5.66666 Round To Thousandths: %f\n", roundToThousandths(5.66666));
    printf("5.66666 Round To Thousandths: %f\n", roundToThousandths(5.66666));
    printf("5.0 Round To Integer: %d\n", roundToInteger(5.0));
}