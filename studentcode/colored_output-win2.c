// code pulled from "https://cboard.cprogramming.com/c-programming/137608-console-colors.html"

#include <stdio.h>
#include <windows.h>
int main ()
{   
     int count;
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      
     for (count=0; count<257; count++)
     {   SetConsoleTextAttribute(hConsole, count);
          printf ("This color combination has the number of %i\n",count); 
     }
      
     SetConsoleTextAttribute(hConsole, 7);
     system ("pause");
     return 0;
}


