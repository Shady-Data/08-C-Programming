/*
# Performance Lab 1

##  Write a program to read the information in storms2.txt. Use the preceding structure and print the information for the hurricanes that
occurred between 1960 and 1969. Use an output format similar to the following:
```
Strongest Hurricanes between 1960 and 1969
Name  Year  Category

```
*/
#include <stdio.h>
#include <string.h>


struct Hurricane{
    char name[25];
    int year;
    int category;
};

int performance_Lab1(void)
{
    FILE * storms = fopen("/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Structure/storms2.txt", "r");
    struct Hurricane temp;
    
    if (storms == NULL){
        printf("failed to open %s\n", "/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Structure/storms2.txt");
    }
    else{
        printf("\tStrongest Hurricanes between 1960 and 1969\n");
        printf("          Name          | Year | Category\n");
        while ( fscanf(storms, "%s %d %d", temp.name, &temp.year, &temp.category) == 3){
            if (temp.year >= 1960 && temp.year <= 1969){
                printf("%23s | %04d | %d\n", temp.name, temp.year, temp.category);
            }
        }
        fclose(storms);
        return 0;
    }

    return 0;
}


/*
# Performance Lab 2

## Write a program that prints out a report giving the Maximum wave height for the tsunamis in "waves2.txt." Include the average wave height(in feet)
and the location of all tsunamis with a wave height higher than the average. 

Example output:
```
Summary Information for Tsunamis
Maximum Wave height ( in feet): 101.68
Average Wave height ( in feet): 42.67
Tsunamis with greater than the average heights:
Flores_Island
Okushiri, _Japan
Eastern_Java
Papua,_New_Guinea
```
*/

struct Tsunami{
    struct Date{
        int month;
        int day;
        int year;
    } date;
    int casualties;
    float wave_height;
    char location[64];
};

float meters2feet(float meters)
{
    return meters * 3.281;
}

float f_average(float * array){
    int count = 0;
    float total = 0;
    while (*array != 0){
        total += *array;
        count++;
        array++;
    }
    return total / count;
}

float f_max(float * array)
{
    float max = 0.0;
    while (*array != 0)
    {
        if (*array > max){
            max = *array;
        }
        array++;
    }
    return max;
}

int performance_Lab2(void)
{
    struct Tsunami temp;
    float wave_Heights[64] = {0};
    float max_waveheight = 0.0;
    float avg_waveheight = 0.0;
    int indexer = 0;
    FILE * waves = fopen("/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Structure/waves2.txt", "r");

    if (waves == NULL){
        printf("failed to open %s\n", "/home/osboxes/Desktop/git_stuff/08-C-Programming/16_Data_Structures/Structure/waves2.txt");
    }
    else{
        while ( fscanf(waves, "%d %d %d %d %f %s", &temp.date.month, &temp.date.day, &temp.date.year, &temp.casualties, &temp.wave_height, temp.location) == 6){
            wave_Heights[indexer] = temp.wave_height;
            indexer++;
        }
        // wave_Heights[indexer] = 0;
        max_waveheight = f_max(wave_Heights);
        avg_waveheight = f_average(wave_Heights);
        fseek(waves, 0, 0);
        printf("Summary Information for Tsunamis:\n");
        printf("\tMaximum Wave height ( in feet): %.2f\n", meters2feet(max_waveheight));
        printf("\tAverage Wave height ( in feet): %.2f\n", meters2feet(avg_waveheight));
        printf("\nTsunamis with greater than the average heights:\n");
        while ( fscanf(waves, "%d %d %d %d %f %s", &temp.date.month, &temp.date.day, &temp.date.year, &temp.casualties, &temp.wave_height, temp.location) == 6){
            if (temp.wave_height > avg_waveheight){
                printf("\t%s\n", temp.location);
            }
        }
    }

    return 0;
}

int main(void)
{
    // performance_Lab1();
    performance_Lab2();

    return 0;
}
