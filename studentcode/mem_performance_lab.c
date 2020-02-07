/*
# Performance Lab Exercises

1. Create a C program get gather input and display text implementing dynamic memory allocation functions

```
*/
#include <stdio.h>
#include <stdlib.h>
#include "myhead.h"

#define BUFF 64

int lab_1(void)
{
    char * str_ptr = calloc(BUFF, sizeof(char));
    char * work_ptr = str_ptr;

    if (str_ptr == NULL){
        puts("Memory allocation failed. Exiting.");
        exit(1);
    }
    printf("Enter a string: ");
    fgets(work_ptr, BUFF - sizeof(char), stdin);

    puts(str_ptr);
    free(str_ptr);
    return 0;
}
/*
PERFORMANCE LAB 2
Follow instructions below!
The basis of this lab is simple... allocate a section of memory that will
hold a string (your first name). Print the name out, then cleanup the memory and exit.
*/

//TODO: Include needed headers
#include <string.h>

int lab_2(void)
{
    //TODO: Create a string containing your first name
    char first_name[] = "Robert";

    //TODO: Get the size of this string
    int str_size = strlen(first_name);
    //TODO: Declare a char pointer *str
    char * str_ptr;


    //TODO: Allocate a section of memory of type char
    //TODO: Set the size of this allocated space to 40 bytes
    //TODO: Asign the address of this allocated space to the pointer value
    char * char_mem_space = malloc(40);
    if (char_mem_space == NULL){
        exit(1);
    }
    str_ptr = char_mem_space;


    //TODO: Copy your name into the allocated space using strcpy()
    strcpy(str_ptr, first_name);
    //TODO: Print out your name that is stored in the allocated memory space
    puts(char_mem_space);
    //TODO: Reallocate the memory space using the size of the string rather than 40 bytes
    //TODO: Print out the string again
    char_mem_space = realloc(char_mem_space, str_size);
    puts(char_mem_space);
    free(char_mem_space);

    return 0;
}
/*
```

3.  Write a program that asks for the current temperature outside as a floating-point value. Have the code ask whether the input 
is Celsius or Fahrenheit. Use malloc() to create storage for the value input. Display the resulting temperature in Kelvin. 
Formula for conversion: 
```
kelvin = celsius + 273.15
kelvin = (fahrenheit + 459.67) * (5.0/9.0);
```
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef BUFF
#undef BUFF
#define BUFF 32
#endif

// Structure of temperature to store a degree and scale together
struct Temperature {
    float degrees;
    char scale;
};

// defined a function to convert degrees celcius to degrees kelvin
float celsius2kelvin(float celsius)
{
    return celsius + 273.15;
}
// defined a function to convert degrees fahrenheit to degrees kelvin
float fahrenheit2kelvin(float fahrenheit)
{
    return (fahrenheit + 459.67) * (5.0 / 9.0);
}

int lab_3(void)
{
    // assign a block of memory to store user input
    char * user_mem_space = malloc(BUFF * sizeof(char));
    // check that the pointer to the memory block is not a NULL pointer
    if (user_mem_space == NULL){
        // If a Null pointer is returned, the memory block failed to allocate
        exit(1); // exit the program
    }
    // assigned a second pointer to the start of the memory block pointer (preserves the start pointer of the block while iterating through the space) 
    char * input_ptr = user_mem_space;
    // declare and initialize a Temperature struct to store user input
    struct Temperature curr_temp;

    // Prompt the usr for input
    printf("Enter the current temperature (in degrees): ");
    // store the degrees input as a float in the current temp degrees member
    scanf("%f", &curr_temp.degrees);
    // clear the input for the next user input prompt
    clear_input();
    // Prompt the user for which temperature scale the degrees member relates to
    printf("Enter the temperature scale :");
    // store the user input characters from stdin up to the number of BUFF - 1 into memory block at the input pointer's current address
    fgets(input_ptr, BUFF - 1, stdin);

    // reset the input pointer to the start of the memory block
    input_ptr = user_mem_space;
    // set the 1st char, as an upper case to the scale member of the current temp variable
    curr_temp.scale = toupper(*input_ptr);
    
    // free the memory block allocation as it's no longer necessary
    free(user_mem_space);

    // depending on the scale member
    switch (curr_temp.scale)
    {
        // if the scale 
    case 'F':
        printf("\nThe current temperature in Kelvin is: %.2f\n", fahrenheit2kelvin(curr_temp.degrees));
        break;
    case 'C':
        printf("\nThe current temperature in Kelvin is: %.2f\n", celsius2kelvin(curr_temp.degrees));
        break;
    case 'K':
        printf("\nThe current temperature was already in Kelvin is: %.2f\n", curr_temp.degrees);
        break;
    default:
        printf("\nThe entered scale was unable to be recognized.\n");
        break;
    }

    return 0;
}

/*
4. Write a program that allocates space for three int values-- an array. You need to use only one malloc()
function to accomplish this task. Assign 100, 200, and 300 to each int, and then display all three values. 
*/

int lab_4(void)
{
    int * array = malloc(3 * sizeof(int));
    int * array_ptr = array;

    for (int i = 1; i < 4; i++){
        *array_ptr = i * 100;
        array_ptr++;
    }
    array_ptr = array;
    for (int i = 1; i < 4; i++){
        printf("\tElement %d : %d\n", i, *array_ptr);
        array_ptr++;
    }
    free(array);

    return 0;
}

/*
5. Modify the source code below and create a second char buffer by using a pointer and malloc().
After text is read by the fgets() function, copy that text from the first buffer(input - from the code) into the second buffer,
all the text except for the newline character, \n at the end  of input. 
```c
*/
#include <stdio.h>
#include <stdlib.h>

int lab_5()
{
    char *input;
    char *output;

    input = (char *)malloc(sizeof(char)*1024);
    output = (char *)malloc(sizeof(char)*1024);
    if(input==NULL || output==NULL)
    {
        puts("Unable to allocate buffers! Oh no!");
        exit(1);
    }
    puts("Type something long and boring:");
    fgets(input,1023,stdin);
    char *in_ptr = input;
    char *out_ptr = output;
    while (*in_ptr != '\n' && in_ptr != NULL){
        *out_ptr = *in_ptr;
        in_ptr++; out_ptr++;
    }
    puts("You wrote:");
    printf("\"%s\"\n",output);
    free(input);
    free(output);

    return(0);
}

/*
```

6. Change your solution from exercise 5, so that the second buffer contains a version of the text in the first buffer
where all the vowels have been replaced with at-signs (@). 
*/

int lab_6()
{
    char *input;
    char *output;

    input = (char *)malloc(sizeof(char)*1024);
    output = (char *)malloc(sizeof(char)*1024);
    if(input==NULL || output==NULL)
    {
        puts("Unable to allocate buffers! Oh no!");
        exit(1);
    }
    puts("Type something long and boring:");
    fgets(input,1023,stdin);
    char *in_ptr = input;
    char *out_ptr = output;
    while (*in_ptr != '\n' && in_ptr != NULL){
        if (tolower(*in_ptr) == 'a' || tolower(*in_ptr) == 'e' || tolower(*in_ptr) == 'i' || tolower(*in_ptr) == 'o' || tolower(*in_ptr) == 'u'){
            *out_ptr = '@';
        }
        else{
            *out_ptr = *in_ptr;
        }
        in_ptr++; out_ptr++;
    }
    puts("You wrote:");
    printf("\"%s\"\n",output);
    free(input);
    free(output);

    return(0);
}

int main(void)
{
    // lab_1();
    // lab_2();
    lab_3();
    // lab_4();
    // lab_5();
    // lab_6();

    return 0;
}