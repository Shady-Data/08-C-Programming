# Structure exercises

1. Change the source code below so that another member is added to the player structure, a float value indicating hours played.
Fix up the rest of the code so taht the new value is input and displayed.

```c

#include <stdio.h>

int main()
{
    struct player
    {
        char name[32];
        int highscore;
    };
    struct player xbox;

    printf("Enter the player's name: ");
    scanf("%s",xbox.name);
    printf("Enter their high score: ");
    scanf("%d",&xbox.highscore);

    printf("Player %s has a high score of %d\n",
            xbox.name,xbox.highscore);
    return(0);
}


```

2. Replace the name member in the human structure with a nested structure. Name that structure id an dhave it contain two members, char arrays,
first and last( or use dynamic memory allocation) for storing an individual's first and last names. When done, the reference to the president's
name will be variables president.name.first and president.name.last. Be sure to assign values to these variables in your code and 
display the results. 

```c
#include <stdio.h>
#include <string.h>

int main()
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    struct human
    {
        char name[45];
        struct date birthday;
    };
    struct human president;

    strcpy(president.name,"George Washington");
    president.birthday.month = 2;
    president.birthday.day = 22;
    president.birthday.year = 1732;

    printf("%s was born on %d/%d/%d\n",
            president.name,
            president.birthday.month,
            president.birthday.day,
            president.birthday.year);

    return(0);
}

```
3. Define a struct type with the name Length that represents a length in yards, feet, and inches. Define an add() 
function that will add two Length arguments and return the sum as type Length. 
Define a second function, show(), that will display the value of its Length argument. 
Write a program that will use the Length type and the add() and show() functions to sum 
an arbitrary number of lengths in yards, feet, and 
inches that are entered from the keyboard and output the total length.

4. Define a struct type that contains a person's name consisting of a first name and a second name, 
plus the person's phone number. Use this struct in a program that will allow one or more names and 
corresponding numbers to be entered and will store the entries in an array of structures. 
The program should allow a second name to be entered and output 
all the numbers corresponding to the name, and optionally output all the names with their corresponding numbers.

5. Write a program to compute the weekly pay for 10 machine shop workers with a 6 character ID, a 20 character name, the hours worked, and the hourly rate of pay. Compute the gross pay with 25% deductions from the gross pay for the net pay. Output the ID, name, hours worked, hourly rate of pay, gross pay, deductions, and net pay. The overtime pay rate over 40 hours is 1.5 times the hourly rate of pay. Organize the data by employee.

