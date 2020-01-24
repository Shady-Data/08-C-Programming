/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28c Copy Char-by-Char
* 
*/

#include <stdio.h>

int main(void)
{
    FILE * infile_ptr = fopen("MMPRlyrics.txt", "r"); // open a file pointer in read mode to the lyrics.txt file
    FILE * outfile_ptr = fopen("MMPRlyrics(copy).txt", "w"); // open a file to write to


    if (infile_ptr != NULL && outfile_ptr != NULL){ // if an error did not occur with the file open
        char reader_file1 = getc(infile_ptr); // declare and initializer a character variable to temporarily store char values from a file
        while (reader_file1 != EOF) // continually iterate until the reader variable is the EOF
        {
            fprintf(outfile_ptr, "%c", reader_file1); // print the character to standard out
            reader_file1 = getc(infile_ptr); // set the reader variable to the next character in the file
        }
        fclose(infile_ptr); // close the open file handler
        fclose(outfile_ptr); // close the open file handler
    }
    else{
        if (infile_ptr == NULL){
            puts("Input/Read file failed to open. Terminating program!"); // print an Error if fopen returned an error for the read
        }
        else if(outfile_ptr == NULL){
            puts("Output/Write file failed to open. Terminating program!"); // print an Error if fopen returned an error for the write
        }
    }

    FILE * verify_ptr = fopen("MMPRlyrics(copy).txt", "r"); // open a file pointer to the out file in "read" mode

    if (verify_ptr != NULL){ // if an error did not occur with the file open
        char reader = getc(verify_ptr); // declare and initializer a character variable to temporarily store char values from a file
        while (reader != EOF) // continually iterate until the reader variable is the EOF
        {
            fprintf(stdout, "%c", reader); // print the character to standard out
            reader = getc(verify_ptr); // set the reader variable to the next character in the file
        }
        fclose(verify_ptr); // close the open file handler
    }
    else {
        puts("Output/write file failed to read for copy verification!"); // print an error if the verification read failed to open
    }

    return 0;
}
