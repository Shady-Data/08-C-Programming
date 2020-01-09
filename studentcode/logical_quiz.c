#include <stdio.h>

int main(void)
{

    int x = 99;
    int y = 0;

    //////// WRITE EACH RESULT ////////
    printf("x = %d, y = %d\n\n", x, y); // starting values

    printf("x && y = %d\n", x && y); // expected results if x = 99 and y = 0: 0
    printf("y || x = %d\n", y || x); // expected results if x = 99 and y = 0: 1
    printf("!y = %d\n", !y); // expected results if x = 99 and y = 0: 1
    printf("y && 0 = %d\n", y && 0); // expected results if x = 99 and y = 0: 0
    printf("x || 42 = %d\n", x || 42); // expected results if x = 99 and y = 0: 1
    printf("!x = %d\n", !x); // expected results if x = 99 and y = 0: 0
    printf("x && x = %d\n", x && x); // expected results if x = 99 and y = 0: 1
    printf("y || y = %d\n", y || y); // expected results if x = 99 and y = 0: 0
    printf("!1 = %d\n", !1); // expected results if x = 99 and y = 0: 0
    printf("1 && 1 = %d\n", 1 && 1); // expected results if x = 99 and y = 0: 1
    printf("(0 && 1) || (2 && 3) = %d\n", (0 && 1) || (2 && 3)); // expected results if x = 99 and y = 0: 1

    return 0;
}