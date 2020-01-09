/* 
* 
*  name: Robert Chunn
*  date: 08 Jan 2020
*  project: Demo Labs 4+5 and Performance Lab 8
*
*  Demo Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/07_scanf.md
*  Perf Lab URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/04_IO_part_1/performance_labs/lab8/lab8.md
*
* Syntax Examples:
* 
* - scanf(“%d,%d”, &num1, &num2);    // Uses comma as delimiter
* - scanf(“%3f”, &GPA);              // Only takes three inputs e.g., 3.4
* - scanf(“*%lf”, &posSqrtTwo);      // Waits for asterisk before reading
* - scanf(“%[abcd]c”, &ansNum1);     // Will only read an a, b, c, or d
* - scanf(“%[A-Z]c”, &capsChar);     // Will only read a capital letter
* - scanf(“%[A-z]c”, &rngOfChar);    // Only chars of decimal value 65–122
* - scanf(“%32[01]s”, binaryStr);    // Stops reading at first non 0 or 1 
* - scanf(“%64[^e\n]s”, Gadsby);     // Stops reading at first e or newline
*/

#include <stdio.h>

// Demo Lab 4

int clear_input(void)
{
    // while loop to grab each char to clear stdin until a newline '\n'
    while ((getchar()) != '\n');

    return 0;
}

int format_input_str(void)
{
    // declare and initialize an array to store user input
    char userInput [21] = {0};
    // Prompt user for input
    printf("Enter a string: ");
    // grab the input from the user
    scanf("%20[^A-Z\n]s", userInput); // [^A-Z\n] will stop capture at the first capital letter or newline
    // clear stdin in to prevent input carryover
    clear_input();
    // print the results for debugging
    printf("\"%s\" was entered.\n", userInput);

    return 0;
}

// Demo Lab 5

int format_input_nums(void)
{
    // declare and initialize an array to store user input
    int numArray [3] = {0};
    //Prompt user for input
    printf("Enter a date in mm-dd-yyyy format: ");
    // get the user's input with scanf
    scanf("%d-%d-%d", &numArray[0], &numArray[1], &numArray[2]);
    // clear stdin in to prevent input carryover
    clear_input();
    // Display the reformated user input
    printf("%02d/%02d/%04d\n", numArray[0], numArray[1], numArray[2]);

    return 0;
}

// Performance Lab 8

int get_full_name(void)
{
    // declare and initialize the 3 char arrays
    char nameFirst [20] = {0};
    char nameMiddle [20] = {0};
    char nameLast [20] = {0};

    // Prompt user for name
    printf("Enter your full name with a tab between each name (i.e. First   Middle  Last):\n");
    scanf("%19s\t%19s\t%19s", nameFirst, nameMiddle, nameLast);
    // clear stdin in to prevent input carryover
    clear_input();
    // Display the entered name
    printf("You Entered: \n");
    printf("\t%s\n\t%s\n\t%s\n", nameFirst, nameMiddle, nameLast);

    return 0;
}

int multiplier(void)
{
    // declare and initialize the variables to store user input in
    int multi[2] = {0};
    // Prompt user for input
    printf("Enter two integers, separated by a *, to be multiplied… (i.e. x*y): ");
    scanf("%d*%d", &multi[0], &multi[1]);
    // clear stdin in to prevent input carryover
    clear_input();
    // Display what the user entered and the product
    printf("The result of %d multiplied by %d is %d.\n", multi[0], multi[1], multi[0] * multi[1]);

    return 0;
}

int main(void)
{
    format_input_str();
    format_input_nums();
    get_full_name();
    multiplier();

    return 0;
}