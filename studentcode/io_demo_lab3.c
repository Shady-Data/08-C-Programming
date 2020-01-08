/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: I/O Demo Lab 3
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/05_string-io.md
*
*/

#include <stdio.h>

int main(void)
{

    char buff[4];                        // Will store string
    printf("Enter string: ");            // Prompts user
    fgets(buff, sizeof(buff), stdin);    // Stores user string
    printf("Your string was: ");         // Prefaces output
    puts(buff);                          // Writes to stdout

    return 0;
}