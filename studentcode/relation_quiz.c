#include <stdio.h>

int main(void)
{

    int x = 2;
    int y = 6;
    //////// WRITE EACH RESULT ////////
    printf("x = %d, y = %d\n\n", x, y); // starting values
    printf("y < x = %d\n", y < x); // expected results when x=2, y=6: 0
    printf("y <= x = %d\n", y <= x); // expected results when x=2, y=6: 0
    printf("y > x = %d\n", y > x); // expected results when x=2, y=6: 1
    printf("y >= x = %d\n", y >= x); // expected results when x=2, y=6: 1
    printf("y == x = %d\n", y == x); // expected results when x=2, y=6: 0
    printf("y != x = %d\n", y != x); // expected results when x=2, y=6: 1
    printf("2 == y = %d\n", 2 == y); // expected results when x=2, y=6: 0
    printf("6 != x = %d\n", 6 != x); // expected results when x=2, y=6: 1
    printf("6 >= 2 = %d\n", 6 >= 2); // expected results when x=2, y=6: 1
    printf("2 < 6 = %d\n", 2 < 6); // expected results when x=2, y=6: 1
    printf("x != y != 3 >= x = %d\n\n", x != y != 3 >= x); // expected results when x=2, y=6: 0

    return 0;
}