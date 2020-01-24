/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28a Mighty Morphin Power Rangers
* 
*/

#include <stdio.h>

int main(void)
{
    FILE * file_ptr = fopen("MMPRlyrics.txt", "r"); // open a file pointer in read mode to the lyrics.txt file


    if (file_ptr != NULL){ // if an error did not occur with the file open
        char reader = getc(file_ptr); // declare and initializer a character variable to temporarily store char values from a file
        while (reader != EOF) // continually iterate until the reader variable is the EOF
        {
            fprintf(stdout, "%c", reader); // print the character to standard out
            reader = getc(file_ptr); // set the reader variable to the next character in the file
        }
        fclose(file_ptr); // close the open file handler
    }
    else{
        puts("File failed to open. Terminating program!"); // print an Error if fopen returned an error
    }

    return 0;
}
