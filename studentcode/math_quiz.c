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
    printf("x *= ++y : x => %d, y => %d\n", x *= ++y);
    printf("x /= y-- : x => %d, y => %d\n", x /= y--);
    printf("x %%= --x : x => %d\n", x %= --x);
    printf("x += --y : x => %d, y => %d\n", x += --y);
    printf("x -= y++ : x => %d, y => %d\n", x -= y++);
    printf("(y %%= y) || (x /= x--) = %d : x => %d, y => %d\n", (y %= y) || (x /= x--));        // Bonus

    return 0;
}