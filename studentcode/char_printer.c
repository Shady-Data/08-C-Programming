#include <stdio.h>

void main()
{
    fprintf(stdout, "Int : Char");
    for (int i = 0; i < 256; i++)
    {
        fprintf(stdout, "%03d : %2c\n", i, (char)i);
    }

}