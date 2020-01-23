// code sourced from "https://en.wikipedia.org/wiki/ANSI_escape_code#Colors"

#include <stdio.h>


void main(void)

{

  int i, j, n;

  

  for (i = 0; i < 11; i++) {

    for (j = 1; j < 11; j++) {

      n = 10*i + j - 1;

      if (n > 108) break;

      printf("\033[%dm %3d\033[m", n, n);

    }

    printf("\n");

  }

}