/* This file contains useful function declarations for myself */

#include <stdio.h>

extern void print_binary(int num)
{
    __uint32_t bitVar = 0x01;
    bitVar <<= 31;

    int space = 0;
    while (bitVar > 0)
    {
        if (space == 4)
        {
            fprintf(stdout, " ");
            space = 0;
        }
        fprintf(stdout, "%d", (num & bitVar) > 0);
        bitVar >>= 1;
        space++;
    }
    // fprintf(stdout, "\n");
}

extern void clear_input()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}