/* 
* 
*  name: Robert Chunn
*  date: 13 Jan 2020
*  project: Performance Lab 15
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/07_Control_flow/performance_labs/Lab15.md
*
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    // declare the char array with a dimension of 256 with all elements being 0s
    char charArray[256] = {0};
    // Assign a phrase to the leading elements in the array
    // charArray[0] = 'I';
    // charArray[1] = ' ';
    // charArray[2] = 'h';
    // charArray[3] = 'a';
    // charArray[4] = 't';
    // charArray[5] = 'e';
    // charArray[6] = ' ';
    // charArray[7] = 'i';
    // charArray[8] = 'n';
    // charArray[9] = 'd';
    // charArray[10] = 'i';
    // charArray[11] = 'v';
    // charArray[12] = 'i';
    // charArray[13] = 'd';
    // charArray[14] = 'u';
    // charArray[15] = 'a';
    // charArray[16] = 'l';
    // charArray[17] = 'l';
    // charArray[18] = 'y';
    // charArray[19] = ' ';
    // charArray[20] = 'a';
    // charArray[21] = 's';
    // charArray[22] = 's';
    // charArray[23] = 'i';
    // charArray[24] = 'g';
    // charArray[25] = 'n';
    // charArray[26] = 'i';
    // charArray[27] = 'n';
    // charArray[28] = 'g';
    // charArray[29] = ' ';
    // charArray[30] = 't';
    // charArray[31] = 'h';
    // charArray[32] = 'e';
    // charArray[33] = 's';
    // charArray[34] = 'e';
    // charArray[35] = ' ';
    // charArray[36] = 'a';
    // charArray[37] = 'r';
    // charArray[38] = 'r';
    // charArray[39] = 'a';
    // charArray[40] = 'y';
    // charArray[41] = ' ';
    // charArray[42] = 'e';
    // charArray[43] = 'l';
    // charArray[44] = 'e';
    // charArray[45] = 'm';
    // charArray[46] = 'e';
    // charArray[47] = 'n';
    // charArray[48] = 't';
    // charArray[49] = 's';
    // charArray[50] = '.';
    // charArray[51] = '.';
    // charArray[52] = '.';
    
    // // explicit addition of 0 or '\0' to terminate the string
    // charArray[53] = 0;
    // declare and initialize a char array that contains the statement to be assigned in to the other array
    char statement[] = "I hate individually assigning these array elements...\0";

    // for loop the iterates i from 0 to the length of the statement schar array
    for (int i = 0; i < strlen(statement); i++)
    {
        // copy the char at the ith position of the statement char array to the other array's ith position (copy array to array)
        charArray[i] = statement[i];
    }

    // print the string
    printf("%s\n", charArray);

    // print the length of the string
    // strlen() from string.h counts characters (memory locations) up to the first null pointer in an array and returns the count
    printf("The length of the string contained in the array is %d, while the size of the array (in memory 'bytes') is %d\n", (int) strlen(charArray), (int) sizeof(charArray));

    return 0;
}