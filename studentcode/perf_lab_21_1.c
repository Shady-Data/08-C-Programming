#include <stdio.h>

unsigned int mystery(unsigned int a, unsigned int b); // function prototype

int main(void)
{
    printf("%s", "Enter two positive integers: ");
    unsigned int x; // first integer
    unsigned int y; // second integer
    scanf("%u%u", &x, &y);

    printf("The result is %u\n", mystery(x, y));
}

// Parameter b must be a positive integer
// to prevent infinite recursion
unsigned int mystery(unsigned int a, unsigned int b)
// this function effectively multiplies a and b by recursively adding a to itself b times
// this function will enter infinite recusion if b less than or equal to 0
{
    // base case
    if (1 == b) {
        return a; // for the value of a for the last recursive call (when b is 1)
    }
    else { // recursive test
        return a + mystery(a, b-1); // add the value of a to the returned value of the next call of the mystery(), decrementing b by 1 each time to get to the base case
    }
}