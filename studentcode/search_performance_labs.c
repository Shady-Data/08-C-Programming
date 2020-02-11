/*
# Performance labs 

## 1. Write a C program that implements a binary search algorithm.
```
Example output:

Array: 5 10 15 20 25 26 34 56 77

Please enter the searched key: 26
The key 26 was found at 5 ( Starting from 0)

```
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search(const int * array, int left_margin, int right_margin, int key2find)
{
    // calculate and store the middle index of the search area of the array by add the left and right margins together and dividing by 2
    int midpoint = (left_margin + right_margin) / 2;
    // if the value at the calculated midpoint of the array is the key to be found
    if ( array[midpoint] == key2find){
        // return the midpoint
        return midpoint;
    }
    // if the value at the calculated midpoint of the array is greater than the key to be found
    else if (array[midpoint] > key2find){
        // return the result of a recursive binary search call using the midpoint as the new right margin
        return binary_search(array, left_margin, midpoint, key2find);
    }
    // if the value at the calculated midpoint of the array is less than the key to be found
    else if (array[midpoint] < key2find){
        // return the result of a recursive binary search call using the midpoint as the new left margin
        return binary_search(array, midpoint, right_margin, key2find);
    }
    else{ // infinite loop if not found?
        // return -1 if an error occured
        return -1;
    }
}

int lab_1(void)
{
    // declare and initialize the array to be searched
    int my_array[] = {5, 10, 15, 20, 25, 26, 34, 56, 77};
    // set a variable to the size of the array
    int array_size = sizeof(my_array) / sizeof(my_array[0]);

    // get the value to be searched for in the array
    int key = 26;

    // get the result of the binary search for the key value in the array starting with 0 for the left margin and the array_size -1 for the right margin
    int result = binary_search(my_array, 0, array_size - 1 , key);

    // if the result is -1
    if (result == -1){
        // display that the key could not be found in the array
        printf("%d was not found in the array.\n", key);
    }
    else{
        // otherwise print index where the key was found
        printf("The key %d was found at %d ( Starting from 0)\n", key, result);
    }

    return 0;
}

/*
### 2. Search the file numbers.txt  that has a sorted 2D array. Create a program to search for
a number from the file and also display something if the number is not found. 


## Real world problems in searching a file:
*/

int lab_2(void)
{
    // declare and zeroize a char array to store user input
    int user_input = 0;
    // prompt for user input
    printf("Enter the number to be searched in the file: ");
    scanf("%d", &user_input);

    // declare and initialize an open file pointer to the file to be searched
    FILE * numbers = fopen("/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Searching/numbers.txt", "r");
    // if the file pointer points to NULL, the file open failed
    if (numbers == NULL){
        // display an error message
        puts("File failed to open. Exitting");
        // exit
        exit(1);
    }
    // file contains rows with 6 columns 4 digit numbers
    // declare and zeroize variables for the number of expected entries
    int entry1 = 0;
    int entry2 = 0;
    int entry3 = 0;
    int entry4 = 0;
    int entry5 = 0;
    int entry6 = 0;
    // declare a pointer array to store the entry address' for iteration
    int * line[6] = {&entry1, &entry2, &entry3, &entry4, &entry5, &entry6};

    // declare and initialize a counter for row
    int row = 0;
    // int col = 0;
    // declare a flag to establish an early while loop break if the value was found
    int flag = 1;

    // while the number of successful entry col assignment is 6 and the flag is not 0 iterate each line of the file
    while (fscanf(numbers, "%d %d %d %d %d %d", &entry1, &entry2, &entry3, &entry4, &entry5, &entry6) == 6 && flag){
        // col = 0;
        // for each column/entry in the line
        for (int col = 0; col < 6; col++){
            // if the user_input value is less than the first stored value in the file
            if (row == 0 && col == 0 && *line[0] > user_input){
                // display a status message that the value can't be in the sorted file
                printf("%d is less than the starting value in the sorted file.\n", user_input);
                // return a -1
                return -1;
            }
            // if the user_value was found in the file
            else if (*line[col] == user_input){
                // print the message where it was found at
                printf("%d was found at row: %d, col: %d (first entry is 0, 0)\n", user_input, row, col);
                // set the flag to 0 to exit the while loop
                flag = 0;
                // break the for loop
                break;
            }
        }
        // increment the row variable at the end of each while loop iteration 
        row++;
    }
    // if the all loop iterations are complete and the flag variable is still set to 1 (True)
    if (flag){
        // print that the value could not be found in the file data
        printf("%d could not be found in the file.\n", user_input);
    }
    return 0;
}


/*
### 3. Power Plant Data. 
The data file power1.txt contains a power plant output in megawatts over a period of 8 weeks.
Each row of data contains 7 integers that represent 1 weeks data. In developing the following programs,
use symbolic constants NROWS and NCOLS to represent the number of rows and the number of columns in the array used to store the data.

A.)Write a program to compute and print the average power output over this period of time.
Also print the number of days with greater-than-average power output.

B.) Write a program to print the day of the week and the number of the week on which the minimum power output occurred.
If there are several days with the minimum power output, print the information for each day.
*/

char * col2day(int day)
{
    switch (day)
    {
    case 0:
        return "Sunday";
        break;
    case 1:
        return "Monday";
        break;
    case 2:
        return "Tuesday";
        break;
    case 3:
        return "Wednesday";
        break;
    case 4:
        return "Thursday";
        break;
    case 5:
        return "Friday";
        break;
    case 6:
        return "Saturday";
        break;

    default:
        return "Failed to Convert";
        break;
    }

}

// void array_above_average(int ** array_2d, int NROWS, int NCOLS, int average){
//     printf("\tDays above the average:\n");
//     for (int row = 0; row <= NROWS; row++){
//         for (int col = NCOLS; col <= NCOLS; col++){
//             if (array_2d[row][col] > average){
//                 printf("Week %d, %s: %d\n", row + 1, col2day(col), array_2d[row][col]);
//             }
//         }
//     }
// }

int lab_3a(void)
{
    // declare and initialize an open file pointer to the file to be searched
    FILE * power = fopen("/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Searching/power1.txt", "r");

    // if the file pointer points to NULL, the file open failed
    if (power == NULL){
        // display an error message
        puts("File failed to open. Exitting");
        // exit
        exit(1);
    }

    int data[52][7] = {0};
    int num_data_entries = 0;
    int NROWS = 0;
    int NCOLS = 0;

    while (fscanf(power, "%d %d %d %d %d %d %d", &data[NROWS][NCOLS], &data[NROWS][NCOLS+1], &data[NROWS][NCOLS+2], &data[NROWS][NCOLS+3], &data[NROWS][NCOLS+4], &data[NROWS][NCOLS+5], &data[NROWS][NCOLS+6]) == 7){
        num_data_entries += 7;
        NROWS++;
    }

    fclose(power);

    int total = 0;
    int average = 0;
    NCOLS = 6;

    for (int y = 0; y <= NROWS; y++){
        for (int x = 0; x <= NCOLS; x++){
            total += data[x][y];
        }
    }

    average = total/num_data_entries;
    printf("Average: %d\n\n", average);

    // array_above_average(&data, NROWS, NCOLS, average);
    printf("\tDays above the average:\n");
    for (int row = 0; row <= NROWS; row++){
        for (int col = NCOLS; col <= NCOLS; col++){
            if (data[row][col] > average){
                printf("Week %d, %s: %d\n", row + 1, col2day(col), data[row][col]);
            }
        }
    }

    printf("\n");

    return 0;
}

int lab_3b(void)
{
    // declare and initialize an open file pointer to the file to be searched
    FILE * power = fopen("/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Searching/power1.txt", "r");

    // if the file pointer points to NULL, the file open failed
    if (power == NULL){
        // display an error message
        puts("File failed to open. Exitting");
        // exit
        exit(1);
    }

    int data[52][7] = {0};
    int num_data_entries = 0;
    int NROWS = 0;
    int NCOLS = 0;

    while (fscanf(power, "%d %d %d %d %d %d %d", &data[NROWS][NCOLS], &data[NROWS][NCOLS+1], &data[NROWS][NCOLS+2], &data[NROWS][NCOLS+3], &data[NROWS][NCOLS+4], &data[NROWS][NCOLS+5], &data[NROWS][NCOLS+6]) == 7){
        num_data_entries += 7;
        NROWS++;
    }

    fclose(power);

    int total = 0;
    int average = 0;
    NCOLS = 6;

    for (int y = 0; y <= NROWS; y++){
        for (int x = 0; x <= NCOLS; x++){

        }
    }
    return 0;
}

int main(void)
{
    // lab_1();
    // lab_2();
    // lab_3a();
    lab_3b();

    return 0;
}