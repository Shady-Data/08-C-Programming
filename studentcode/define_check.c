#include <stdio.h>
#define BUFSIZE 10
#define UNIT "90COS"

#define STRINGIFY_FOR_REAL(x) #x
#define STRINGIFY(a) STRINGIFY_FOR_REAL(a)
#define PASTE_FOR_REAL(x, y) x##y
#define PASTE(a, b) PASTE_FOR_REAL(a,b)

int main(void)
{
    char myArray[BUFSIZE] = {UNIT};
    puts(myArray);

    puts(STRINGIFY(PASTE(Bill, Ding)));
    puts(STRINGIFY_FOR_REAL(PASTE_FOR_REAL(Brock, Lee)));	
    // BUFSIZE++;

    return 0;
}