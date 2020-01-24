/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28e Usernames
* 
*/

#include <stdio.h>

#define BUFF 64

void get_name(char * first, char * middle, char * last) // get a first, middle, and last name from stdin
{
    fscanf(stdin, "%63s %63s %63s", first, middle, last);
}

void write_outfile(char * filename, char * writeLines) // write lines from a preformatted 2D array to a file
{
    FILE * outfile = fopen(filename, "w");

    if (outfile != NULL){
        for (int i = 0; i < sizeof(writeLines)/sizeof(writeLines[0]); i++){
            fputs(writeLines[i], outfile);
        }
    }
    else {
        printf("Failed to write %s!\n", filename);
    }
}