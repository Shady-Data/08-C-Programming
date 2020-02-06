
# Performance Lab Exercises

1. Create a C program get gather input and display text implementing dynamic memory allocation functions

```
2. /*
PERFORMANCE LAB 2
Follow instructions below!
The basis of this lab is simple... allocate a section of memory that will
hold a string (your first name). Print the name out, then cleanup the memory and exit.
*/

//TODO: Include needed headers


int main(void)
{
    //TODO: Create a string containing your first name

    //TODO: Get the size of this string

    //TODO: Declare a char pointer *str



    //TODO: Allocate a section of memory of type char
    //TODO: Set the size of this allocated space to 40 bytes
    //TODO: Asign the address of this allocated space to the pointer value


    //TODO: Copy your name into the allocated space using strcpy()

    //TODO: Print out your name that is stored in the allocated memory space

    //TODO: Reallocate the memory space using the size of the string rather than 40 bytes
    //TODO: Print out the string again


}
```

3.  Write a program taht asks for the current temperature outside as a floating-point value. Have the code ask whether the input 
is Celsius or Fahrenheit. Use malloc() to create storage for the value input. Display the resulting temperature in Kelvin. 
Formula for conversion: 
```
kelvin = celsius + 273.15
kelvin = (fahrenheit + 459.67) * (5.0/9.0);
```
4. Write a program that allocates space for three int values-- an array. You need to use only one malloc() function to accomplish this task. Assign 100, 200, and 300 to each int, and then display all three values. 

5. Modify the source code below and create a second char buffer by using a pointer and malloc(). After text is read by the fgets() function, copy that text from the first buffer(input - from the code) into the second buffer, all the text except for the newline character, \n at the end  of input. 
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *input;

    input = (char *)malloc(sizeof(char)*1024);
    if(input==NULL)
    {
        puts("Unable to allocate buffer! Oh no!");
        exit(1);
    }
    puts("Type something long and boring:");
    fgets(input,1023,stdin);
    puts("You wrote:");
    printf("\"%s\"\n",input);

    return(0);
}


```

6. Change your solution from exercise 5, so that the second buffer contains a version of the text in the first buffer where all the vowels have been replaced with at-signs (@). 
