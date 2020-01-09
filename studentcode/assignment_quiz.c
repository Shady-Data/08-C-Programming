#include <stdio.h>

int main(void)
{
    int x = 9;
    int y = 3;
    //////// WRITE EACH VALUE OF X ////////
    printf("x = %d, y = %d\n\n", x, y);

    printf("x *= y : x => %d\n", x *= y);
    printf("x /= y : x => %d\n", x /= y);
    printf("x %%= y : x => %d\n", x %= y);
    printf("x += y : x => %d\n", x += y);
    printf("x -= y : x => %d\n", x -= y);
    printf("x *= ++y : x => %d, y => %d\n", x *= ++y , y);
    printf("x /= y-- : x => %d, y => %d\n", x /= y--, y - 1);
    printf("x %%= --x : x => %d\n", x %= --x);
    printf("x += --y : x => %d, y => %d\n", x += --y, y);
    printf("x -= y++ : x => %d, y => %d\n", x -= y++, y + 1);
    x = 9; // reset x = 9 to prevent a floating point error exception (zero division error)
    y = 3;
    // printf("(y %%= y) || (x /= --x) = %d : x => %d, y => %d\n", (y %= y) || (x /= --x), x, y);        // Bonus
    printf("(y %%= y) || (x /= x--) = %d : x => %d, y => %d\n", (y %= y) || (x /= x--), x, y);        // Bonus

    return 0;
}