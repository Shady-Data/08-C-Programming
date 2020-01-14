#include <stdio.h>

void main()
{
    char userInput = 0;
    printf("Press a key on your keyboard to attempt to get the decimal equivalent value: ");
    userInput = getchar();
    printf("%c = %d\n", userInput, (int)userInput);
}