#include <stdio.h>

int main(void)
{
    // first
    int computerScienceCourses [] = {1003, 1023, 1033, 1063, 1073};
    printf("Computer Science Courses (index : value): ");
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf(" %2d : %6d,", i, computerScienceCourses[i]);
    }
    printf("\n");


    // second
    float studentGPAs [] = {2.7, 3.1, 2.9, 4, 3.9, 2.89, 3.55};
    printf("Student GPAs (index : value): ");
    for (i = 0; i < 7; i++)
    {
        printf(" %2d : %6.2f,", i, studentGPAs[i]);
    }
    printf("\n");

    // third
    char cardinalDirections [4] = {0};
    printf("Cardinal Directions (index : value): ");
    for (i = 0; i < 4; i++)
    {
        printf(" %2d : %c,", i, cardinalDirections[i]);
    }
    printf("\n");
    // fourth
    char catchPharse [10] = {76, 101, 103, 101, 111};
    printf("Catch Phrase (index : value): ");
    for (i = 0; i < 10; i++)
    {
        printf(" %2d : %c,", i, catchPharse[i]);
    }
    printf("\n");

    return 0;
}