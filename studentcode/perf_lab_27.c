/*
* 
*  name: Robert Chunn
*  date: 22 Jan 2020
*  project: Performance Lab 27
* 
*/

#include <stdio.h>
#include <string.h>

#define ERROR_NULL_POINTER "Error! Null Pointer!"
#define ERROR_ABUNDANT_POINTER "Error! Too many delimiters found!"
#define ERROR_NULL_DELIMITER "Error! NULL delimiter"

char * split_the_string(char * string_ptr, char delimiter)
{
    int delim_count = 0;
    char * delim_ptr = string_ptr;
    if (*string_ptr == '\0' || string_ptr == NULL){
        return ERROR_NULL_POINTER;
    }

    if (delimiter == '\0'){
        return ERROR_NULL_DELIMITER;
    }

    while (*string_ptr != '\n' && *string_ptr != '\0'){
        if (*string_ptr == delimiter){
            if (delim_count == 0){
                delim_count++;
                delim_ptr = string_ptr;
            }
            else{
                return ERROR_ABUNDANT_POINTER;
            }
        }
        string_ptr++;
    }
    
    if (delim_count == 0){
        return delim_ptr;
    }
    else{
        return delim_ptr + 1;
    }
}

int main(void)
{
    char my_string1[] = "Lets give this a ,try with one comma!";
    char my_string2[] = "Lets give this a ,try with, two commas!";
    char my_string3[] = "Lets give this a try with no commas!";
    char my_string4[] = "Lets give this a \0try with a NULL char!";
    for (int i = 0; i < 4; i++){
        switch (i)
        {
        case 0:
            printf("%s\n", split_the_string(my_string1, ','));
            break;
        case 1:
            printf("%s\n", split_the_string(my_string2, ','));
            break;
        case 2:
            printf("%s\n", split_the_string(my_string3, ','));
            break;
        case 3:
            printf("%s\n", split_the_string(my_string4, '\0'));
            break;

        default:
        printf("Loop exceeded expected cases.\n");
            break;
        }
    }

    return 0;
}