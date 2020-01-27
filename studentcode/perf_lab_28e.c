/*
* 
*  name: Robert Chunn
*  date: 24 Jan 2020
*  project: Performance Lab 28e Usernames
* 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "myhead.h"

int main(void)
{
    // declare and zeroize a variable to store user input for the number of entries
    int numStudents = 0;
    // Get the number of students
    printf("How many students?\n");
    scanf("%d", &numStudents); 
    clear_input(); // clear stdin to prevent errors
    // Open the file in append mode
    FILE * roster = fopen("roster.dat", "a");
    // Declare and zeroize a char array to store a string from user input
    char name[256] = {0};
    // While loop to get the right number of names
    printf("Enter the student's full name\n");
    while (numStudents > 0)
    {
        // Declare/initialize output string
        char username[256] = {0};
        int entry = 1;
        // Get user input
        printf("Entry %d: ", entry++);
        // [^\n] does not grab the trailing newline
        scanf("%[^\n]255s", name);
        clear_input(); // clear stdin to prevent errors
        // Convert the input to lower case
        for (int i = 0; name[i] != 0; i++) // iterate 
        {
            name[i] = tolower(name[i]);
        }
        // For loop, split the string on spaces, continue grabbing the next segment until none are left
        char * tok_ptr = strtok(name, " "); // declare and initialize a char pointer to be the strtok() result of the name variable with a ' ' token delimiter
        for (int i = 0; tok_ptr != NULL; tok_ptr = strtok(NULL, " "), i++) // loops until tok_ptr variable != NULL and reassigns tok_ptr to the next <space> seperated segment and increments i on each loop iteration
        {
            while (strlen(username) > i) // while the return of strlen() of username is greater than i continually iterate the following code
            {
                username[strlen(username) - 1] = 0; // set the char in username at the last position to be the integer 0
            }
            strcat(username, tok_ptr); // concatenate the tok_ptr variable to username
        }
        // Put the output string and a newline to the txt file
        fputs(username, roster);
        fputs("\n", roster);
        // Decrement the loop
        numStudents--;
    }
    // Close the file and end the program
    fclose(roster);
    return 0;
}