// code pulled from stack overflow at: "https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c"

#include <stdio.h>
#include <windows.h>

int main (int argc, char const *argv[]) {

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;

  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
  printf("This text is RED!\n");
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
  printf("This text is GREEN!\n");
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
  printf("This text is YELLOW!\n");
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
  printf("This text is BLUE!\n");
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
  printf("This text is MAGENTA!\n");
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
  printf("This text is CYAN!\n");
  SetConsoleTextAttribute(hConsole, saved_attributes);

  return 0;
}

