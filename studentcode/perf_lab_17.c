/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 17
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab17.md
*
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // declare and zeroize a 26 element int array
    int myCharCounter[26] = {0};
    // declare and zeroize a char variable
    char myChar = 0;
    char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

    // declare and initialize an index pointer
    int ind = 0;
    // prompt for user input
    fprintf(stdout, "Enter a string: ");

    do
    {
        // grab a single character from stdin 
        myChar = getc(stdin);
        // check if the character is within the uppercase range (65-90) or the lowercase range (97-122)
        if (((int)myChar >= 65 && (int)myChar <= 90) || ((int)myChar >=97 && (int)myChar <= 122))
        {
            // use the toupper() in ctype.h to convert a lowercase letter to an uppercase letter
            myChar = toupper(myChar);
            
            // increment the appropriate counter in the char counter array
            myCharCounter[(int)myChar - 65] += 1;
        }
    // do all this while a newline \n is read, or until the int array is full
    } while (myChar != '\n');
    
    // until the for i >= the length of the int array
    // The length of the array is determined taking the sizeof() the array (in memory), and divides it by the sizeof() one element of the array to return the total number of elements in the array
    for (int i = 0; i < (sizeof(myCharCounter)/sizeof(myCharCounter[0])); i++)
    {
        // print the stored values in the array at the ith position
        fprintf(stdout, "\t%c : %d\n", upper[i], myCharCounter[i] );
    }

    return 0;
}