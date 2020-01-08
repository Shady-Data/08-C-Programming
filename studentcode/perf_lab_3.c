/* 
* 
*  name: Robert Chunn
*  date: 06 Jan 2020
*  project: Perf Lab 3
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/03_Arrays_strings/performance_labs/lab3/lab3.md
*
* Requirements: 
*
* - Student ages (all ages are made up, no actual ages are used in this program)
*
*   - Declare and zeroize an int array with a dimension equal to the number of students + 1
*   - Set index 0 with the age* of the instructor
*   - Fill the elements of the array with the ages* of the students starting with index 1
*   - Print the array
* 
* - Favorite quote
* 
*   - Declare and initialize a char array with your favorite saying
*   - Ensure the last index is set to nul ('\0')
*   - Separate each word in the array with a new line character ('\n' or decimal value 10)
* 
* NOTE: * use your best guess
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numStudents = 14; // number of students in the class 
    int studentsAge [numStudents + 1]; // declare an int array with the number of students + 1
    // int ages [14] = {27, 29, 31, 33, 35, 34, 32, 30, 31, 29, 28, 27, 26, 25}; //array to quick assign ages

    // set index 0 of the age array to the instructor's age
    studentsAge[0] = 37;

    // iterate through the remaining indexes and assign an age for each element
    for (int i=1; i<numStudents+1; i++) // start at index 1 to the number of students + 1
    {
        studentsAge[i] = (rand() % (45 - 25)) + 24; // rng in range => (rand() % (upper - lower + 1) + lower)
    }

    // print the students ages array
    printf("Students ages (index:age):\n");
    for (int i=0; i < numStudents+1; i++)
    {
        printf("\t%2d : %2d\n", i, studentsAge[i]);
    }

    // char quote[] = {'I','\n','d','o','n','\'','t','\n','h','a','v','e','\n','a','\n','f','a','v','o','r','i','t','e','\n','q','u','o','t','e','\n','a','t','\n','t','h','e','\n','m','o','m','e','n','t','\0'};
    // printf("\n\n");
    // for (int i=0; i < sizeof(quote)/sizeof(quote[0]); i++)
    // {
    //     printf("%c", quote[i]);
    // }
    // printf("\n");

    char quote[] = "I don't have a favorite quote at the moment";
    quote[-1] += '\0';
    int i = 0;
    char revisedQuote[sizeof(quote)/sizeof(quote[0])];
    while ( quote[i] != '\0')
    {
        if ( quote[i] == ' '){
            // printf("\n");
            revisedQuote[i] = '\n';
        }
        else{
            // printf("%c", quote[i]);
            revisedQuote[i] = quote[i];
        }
        i++;
    }
    // check result by printing the revised array
    // printf("%s", revisedQuote);
    // printf("\n");

    return 0;
}