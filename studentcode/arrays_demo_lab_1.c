/*
* 
*  name: Robert Chunn
*  date: 06 Jan 2020
*  project: Demo Lab 2
*
*  URL: https://github.com/CyberTrainingUSAF/08-C-Programming/blob/master/03_Arrays_strings/03_access_modify_Arrays.md
*/

#include <stdio.h>

int main(void)
{
    int myIntArray[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    float myFloatArray[5] = {1, 2, 3, 4, 5};
    char myCharArray[256] = {0};

    printf("Third element in each array:\n");
    printf("%d\n", myIntArray[2]);
    printf("%f\n", myFloatArray[2]);
    printf("%c\n\n", myCharArray[2]);

    //myIntArray modifications
    int i = 0;
    for (i=0; i < 10; i++)
    {
        myIntArray[i] = (i+1) * 10;
    }

    //myFloatArray modifications
    for (i=0; i < 5; i++)
    {
        myFloatArray[i] *= 1.1;
    }

    //myCharArray modifications
    myCharArray[0] = 'C';
    myCharArray[1] = 'h';
    myCharArray[2] = 'u';
    myCharArray[3] = 'n';
    myCharArray[4] = 'n';

    printf("Third element in each array after modification:\n");
    printf("%d\n", myIntArray[2]);
    printf("%f\n", myFloatArray[2]);
    printf("%c\n\n", myCharArray[2]);

    return 0;
}