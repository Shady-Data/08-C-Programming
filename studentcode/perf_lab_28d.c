/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28d Copy line-by-line
* 
*/

#include <stdio.h>
#define BUFFSIZE 256 // defined buffer size of 256

int main(void)
{
    FILE * infile_ptr = fopen("SOAD_ChopSuey.txt", "r"); // open a file pointer in read mode to the lyrics.txt file
    FILE * outfile_ptr = fopen("SOAD_ChopSuey(copy).txt", "w"); // open a file to write to

    if (infile_ptr != NULL && outfile_ptr != NULL){ // if an error did not occur with the file open
        char reader[BUFFSIZE] = {0}; // declare and initializer a character array variable to temporarily store lines from a file
        char * templine_ptr = reader; // pointer variable to store the result of fgets()

        while (templine_ptr) // continually iterate until the pointer is the EOF/Empty
        {
            templine_ptr = fgets(reader, BUFFSIZE, infile_ptr); // set the reader variable to the next line in the file
            if (templine_ptr){ // if the templine pointer is not empty/EOF
                fputs(reader, outfile_ptr); // print the string/line to standard out
            }
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

    FILE * verify_ptr = fopen("SOAD_ChopSuey(copy).txt", "r"); // open a file pointer to the out file in "read" mode

    if (verify_ptr != NULL){ // if an error did not occur with the file open
        char verifier[BUFFSIZE] = {0}; // declare and initializer a character variable to temporarily store char values from a file
        char * tempVerify_ptr = verifier; // pointer variable to store the result of fgets()

        while (tempVerify_ptr) // continually iterate until the pointer is the EOF/Empty
        {
            tempVerify_ptr = fgets(verifier, BUFFSIZE, verify_ptr); // set the reader variable to the next line in the file
            if (tempVerify_ptr){ // if the templine pointer is not empty/EOF
                fputs(verifier, stdout); // print the string/line to standard out
            }
        }
    }
    else {
        puts("Output/write file failed to read for copy verification!"); // print an error if the verification read failed to open
    }

    return 0;
}
