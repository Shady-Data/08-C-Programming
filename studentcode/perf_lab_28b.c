/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28b Your Song
* 
*/

#include <stdio.h>
#define BUFFSIZE 256 // defined buffer size of 256

int main(void)
{
    FILE * file_ptr = fopen("SOAD_ChopSuey.txt", "r"); // open a file pointer in read mode to the lyrics.txt file


    if (file_ptr != NULL){ // if an error did not occur with the file open
        char reader[BUFFSIZE] = {0}; // declare and initializer a character array variable to temporarily store lines from a file
        char * templine_ptr = reader; // pointer variable to store the result of fgets()

        while (templine_ptr) // continually iterate until the pointer is the EOF/Empty
        {
            templine_ptr = fgets(reader, BUFFSIZE, file_ptr); // set the reader variable to the next line (up to the buffer) in the file
            if (templine_ptr){ // if the templine pointer is not empty/EOF
                fputs(reader, stdout); // print the string/line to standard out
            }
        }
        fclose(file_ptr); // close the open file handler
    }
    else{
        puts("File failed to open. Terminating program!"); // print an Error if fopen returned an error
    }

    return 0;
}
