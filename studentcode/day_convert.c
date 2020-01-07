/* This Program takes and integer of days and converts is to a number of years, weeks, and days
*
*  name: Robert Chunn
*  date: 06 Jan 2020
*  project: day converter
*/

#include <stdio.h>

int main(void)
{
    int startDays;  // declare an int variable to store a number of days input by the user
    int years, weeks, remainDays; // declare remaining years, weeks, and a remainingDays (remainingDays will be the working variable to preserve the user input)

    // Get the number of days to convert from the user
    printf("Enter the number of days to be converted: ");
    scanf("%d", &startDays);

    // Set the working remainingDays to be equal to the user input start days
    remainDays = startDays;
    // calculate the number of 365-day years
    years = remainDays / 365;
    // remainDays = remainDays - (years * 365);
    remainDays = remainDays % 365;
    // calculate the number of weeks
    weeks = remainDays / 7;
    // remainDays = remainDays - (weeks * 7);
    remainDays = remainDays % 7;
    // print the results
    printf("%d years, %d weeks, %d days\n", years, weeks, remainDays);

    return 0;
}