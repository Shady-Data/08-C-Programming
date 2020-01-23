/*
* 
*  name: Robert Chunn
*  date: 22 Jan 2020
*  project: Performance Lab 27
* 
*/

#include <stdio.h>
// #include <string.h>

#define ANSI_FLASH         "\x1b[5m" // Applies a flashing effect to the text following this sequence
#define ANSI_COLOR_RED     "\x1b[31m" // Prints the text in a red color following this sequence
#define ANSI_COLOR_RESET   "\x1b[0m" // resets the text/terminal effects to defaults after this sequence

#define RED_ERROR ANSI_COLOR_RED ANSI_FLASH "\tERROR! " ANSI_COLOR_RESET // prints a tabbed over, red, flashing ERROR! Text 

#define ERROR_NULL_POINTER "NULL Pointer/Empty String found!" // custom ERROR message due to ((char *) -1) causing segmentation faults when called
#define ERROR_ABUNDANT_POINTER "More than 1 occurence of the delimiter character found!" // custom ERROR message due to ((char *) -2) causing segmentation faults when called
#define ERROR_NULL_DELIMITER "NULL character/No Character passed for the delimiter split value!" // custom ERROR message due to ((char *) -3) causing segmentation faults when called

char * split_the_string(char * string_ptr, char delimiter) // takes a pointer to a string (char array) and a delimiter character and returns the first char after the delimiter character if only one delimiter character is found
{
    int delim_count = 0; // declare and initialize a delimiter counter to increment for each occurence
    char * delim_ptr = string_ptr; // declare and initialize a character pointer to initial value of the string_ptr parameter
    if (*string_ptr == '\0' || (int *)string_ptr == NULL){ // if the string_ptr parameter points to an empty string or NULL (currently NULL pointer causes a segmentation fault when found)
        return ERROR_NULL_POINTER; // return the ERROR_NULL_POINTER message
    }

    if (delimiter == '\0'){ // if the delimiter passed is a NULL character '\0'
        return ERROR_NULL_DELIMITER; // return the ERROR_NULL_DELIMITER message
    }

    while (*string_ptr != '\n' && *string_ptr != '\0'){ // while the value at the current string_ptr position is not a newline '\n' and not NULL '\0'
        if (*string_ptr == delimiter){ // if the value at the current sting_ptr position is the same as the delimiter character
            if (delim_count == 0){ // if this is the first occurence of the delimiter character
                delim_count++; // increment the delimiter counter
                delim_ptr = string_ptr + 1; // set the delimiter pointer to be the character after the found delimiter character
            }
            else{ // if more than one occurence of the delimiter character is found
                return ERROR_ABUNDANT_POINTER; // stop iteration and return the ERROR_ABUNDANT_POINTER message
            }
        }
        string_ptr++; // increment the string_ptr to the next address pointer for iteration
    }
    
    return delim_ptr; // return the delimiter pointer (initialize as the start of the string (returns what was passed if no delimiter character was found) and reassign if the delimiter character was found)
}

int main(void)
{
    // declare and initialize several strings to test the split_the_string() function
    char my_string1[] = "Lets give this a ,try with one comma!";
    char my_string2[] = "Lets give this a ,try with, two commas!";
    char my_string3[] = "Lets give this a try with no commas!";
    char my_string4[] = "Lets give this a \0try with a NULL char!";
    char my_string5[] = "";
    // to reduce code, add string arrays to a char pointer array that points to the start of each array
    char * multiStringArrays[] = {my_string1, my_string2, my_string3, my_string5};
    // declare a char pointer to be a temp value
    char * tempValue_ptr;
    // iterate for each of the array's in the char pointer array
    for (int i = 0; i < sizeof(multiStringArrays)/sizeof(*multiStringArrays); i++){
        // set the tempValue_ptr to the return of the split_the_string of the current ith array in the char pointer array
        tempValue_ptr = split_the_string(multiStringArrays[i], ',');
        // if the temp value is one of the error messages
        if (tempValue_ptr == ERROR_NULL_POINTER || tempValue_ptr == ERROR_ABUNDANT_POINTER || tempValue_ptr == ERROR_NULL_DELIMITER){
            printf(RED_ERROR "%s\n", tempValue_ptr); // print the tabbed, flashing, red ERROR! and the returned error message stored in tempValue_ptr
        }
        else{ 
            printf("%s\n", tempValue_ptr); // otherwise print out a the string starting at the pointer stored in tempValue_ptr to the end (first null char) in the array's memory space
        }
    }
    tempValue_ptr = split_the_string(my_string4, '\0'); // for the outlier to check, set tempValue_ptr to the return of split_the_string() function with the NULL character delimiter
    if (tempValue_ptr == ERROR_NULL_POINTER || tempValue_ptr == ERROR_ABUNDANT_POINTER || tempValue_ptr == ERROR_NULL_DELIMITER){ // if the temp value is one of the error messages
        printf(RED_ERROR "%s\n", tempValue_ptr); // print the tabbed, flashing, red ERROR! and the returned error message stored in tempValue_ptr
    }
    else{
        printf("%s\n", tempValue_ptr); // otherwise print out a the string starting at the pointer stored in tempValue_ptr to the end (first null char) in the array's memory space
    }
    return 0;
}