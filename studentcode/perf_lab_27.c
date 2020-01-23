/*
* 
*  name: Robert Chunn
*  date: 22 Jan 2020
*  project: Performance Lab 27
* 
*/

#include <stdio.h>
#include <string.h>

#define ANSI_FLASH         "\x1b[5m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define RED_ERROR ANSI_COLOR_RED ANSI_FLASH "\tERROR! " ANSI_COLOR_RESET

#define ERROR_NULL_POINTER "NULL Pointer/Empty String found!"
#define ERROR_ABUNDANT_POINTER "More than 1 occurence of the delimiter character found!"
#define ERROR_NULL_DELIMITER "NULL character/No Character passed for the delimiter split value!"

char * split_the_string(char * string_ptr, char delimiter)
{
    int delim_count = 0;
    char * delim_ptr = string_ptr;
    if (*string_ptr == '\0' || (int *)string_ptr == NULL){
        return ERROR_NULL_POINTER;
    }

    if (delimiter == '\0'){
        return ERROR_NULL_DELIMITER;
    }

    while (*string_ptr != '\n' && *string_ptr != '\0'){
        if (*string_ptr == delimiter){
            if (delim_count == 0){
                delim_count++;
                delim_ptr = string_ptr + 1;
            }
            else{
                return ERROR_ABUNDANT_POINTER;
            }
        }
        string_ptr++;
    }
    
    return delim_ptr;
}

int main(void)
{
    char my_string1[] = "Lets give this a ,try with one comma!";
    char my_string2[] = "Lets give this a ,try with, two commas!";
    char my_string3[] = "Lets give this a try with no commas!";
    char my_string4[] = "Lets give this a \0try with a NULL char!";
    char my_string5[] = "";
    char * multiStringArrays[] = {my_string1, my_string2, my_string3, my_string5};
    char * tempValue_ptr;
    for (int i = 0; i < sizeof(multiStringArrays)/sizeof(*multiStringArrays); i++){
        tempValue_ptr = split_the_string(multiStringArrays[i], ',');
        if (tempValue_ptr == ERROR_NULL_POINTER || tempValue_ptr == ERROR_ABUNDANT_POINTER || tempValue_ptr == ERROR_NULL_DELIMITER){
            printf(RED_ERROR "%s\n", tempValue_ptr);
        }
        else{
            printf("%s\n", tempValue_ptr);
        }
        // switch (i)
        // {
        // case 0:
        //     printf("%s\n", split_the_string(my_string1, ','));
        //     break;
        // case 1:
        //     printf("%s\n", split_the_string(my_string2, ','));
        //     break;
        // case 2:
        //     printf("%s\n", split_the_string(my_string3, ','));
        //     break;
        // case 3:
        //     printf("%s\n", split_the_string(my_string4, '\0'));
        //     break;
        // case 4:
        //     printf("%s\n", split_the_string(my_string5, ','));
        //     break;

        // default:
        // printf("Loop exceeded expected cases.\n");
        //     break;
        // }
    }
    tempValue_ptr = split_the_string(my_string4, '\0');
    if (tempValue_ptr == ERROR_NULL_POINTER || tempValue_ptr == ERROR_ABUNDANT_POINTER || tempValue_ptr == ERROR_NULL_DELIMITER){
        printf(RED_ERROR "%s\n", tempValue_ptr);
    }
    else{
        printf("%s\n", tempValue_ptr);
    }
    return 0;
}