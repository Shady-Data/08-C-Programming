/*
* 
*  name: Robert Chunn
*  date: 16 Jan 2020
*  project: Performance Lab 21_4
* 
* (palindrome): Write a recursive function that returns a value of 1 if its string argument is a palindrome, 0 otherwise.
* Notice that in palindromes such as level, deed, sees, and madam...the first letter matches the last.
*/

#include <stdio.h>
#include <string.h>

int check_palindrome(char * string, int stringLength, int index)
// This function takes a string, the string's length (could be substituted with the stop index + 1), and a starting index value (normally 0) 
{
    if (string[index] != string[(stringLength - 1) - index]) { // base case 1: if the char at the index position is not equal to the char at the position of the difference of stringLenth - the index - 1
        return 0; // string is not a palindrome, return 0
    }
    else if (index > stringLength / 2) { // base case 2: if the index value is greater than or equal to half of the stringLenth value and the first condition has not been met
        return 1; // all chars have been checked and the string is a palindrome
    }
    else // recursive case:
    {
        return check_palindrome(string, stringLength, index + 1); // recursively call this function incrementing the index for the next check until a 1 or 0 is returned
    }
}

int main(void)
{
    // declare test arrays
    char test1[] = "level";
    char test2[] = "deed";
    char test3[] = "sees";
    char test4[] = "madam";
    char test5[] = "palindrome";
    char test6[] = "racecar";
    char test7[] = "acloseresultsuseresolca";
    char * testArrays[] = {test1, test2, test3, test4, test5, test6, test7};
    // declare a temporary value to store results into
    int tempResult = 0;

    // iterate throught the tests to calling check_palindrome for each test
    for (int i = 0; i < (sizeof(testArrays) / sizeof(*testArrays)); i++)
    {
        // set tempResult to the return of check_palindrome() for the current iteration
        tempResult = check_palindrome(testArrays[i], strlen(testArrays[i]), 0);
        // if the result is 1
        if (tempResult == 1){
            printf("%s is a palindrome\n", testArrays[i]); // print that the string is a palindrome
        }
        else{ // otherwise
            printf("%s is not a palindrome\n", testArrays[i]); // print that the string is not a palindrom
        }
    }

    return 0;
}