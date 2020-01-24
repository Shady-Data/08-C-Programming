/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28e Usernames
* 
*/

#include <stdio.h>
#include <ctype.h>

#define BUFF 256

void get_name(char * names) // get a first, middle, and last name from stdin
{
    fscanf(stdin, "%255s", names);
}

void write_outfile(char * filename, char * students, char * usernames) // write the arrays to the outputfile
{
    FILE * outfile = fopen(filename, "w");

    if (outfile != NULL){
        for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++){
            fputs(students[i], outfile);
            fputs(" has a username of " , outfile);
            fputs(usernames[i], outfile);
            fputs("\n", outfile);
        }
    }
    else {
        printf("Failed to write %s!\n", filename);
    }
}

int count_splits(const char * string)
{
    int count = 0;
    char * temp_ptr = string;
    while (temp_ptr != '\n' && temp_ptr != '\0')
    {
        temp_ptr++;
        if (temp_ptr == ' ' || temp_ptr == '-' || temp_ptr == '_'){
            count++;
        }
    }
    return count;
}

int main(void)
{
    // declare and zeroize a char array to store user input
    char userInput[BUFF] = {0};
    // declare an input variable to store the number of students to enter
    int students = 0;
    // declare an array to store the students info in for writing to a file
    char allStudents[64][BUFF];
    char userNames[64][BUFF];
    int nameSplits = 0, stud = 0, ch = 0;
    char * temp_ptr;
    // Prompt the user for the number of students to be entered
    puts("Enter the First Middle and Last name for each student:");
    while (students > 0){
        get_name(userInput);
        allStudents[stud][sizeof(userInput)] = userInput;
        temp_ptr = userInput;
        nameSplits = count_splits(userInput);
        while (nameSplits > 1){
            userNames[stud][ch] = tolower(*temp_ptr);
            ch++;
            while (*temp_ptr != '-' || *temp_ptr != '_' || *temp_ptr != ' '){
                temp_ptr++;
            }
            temp_ptr++;
            nameSplits--;
        }
        while (*temp_ptr != '\n' || *temp_ptr != '\0' || *temp_ptr != NULL){
            userNames[stud][ch] = tolower(*temp_ptr);
            ch++; temp_ptr++;
        }
        stud++;
        students--;
    }   
    write_outfile("roster.txt", allStudents, userNames);

    return 0;
}