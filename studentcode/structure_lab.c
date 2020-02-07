/*
# Structure exercises

1. Change the source code below so that another member is added to the player structure, a float value indicating hours played.
Fix up the rest of the code so taht the new value is input and displayed.

```c
*/
#include <stdio.h>

int example1()
{
    struct player
    {
        char name[32];
        int highscore;
        float hours_played;
    };
    struct player xbox;

    printf("Enter the player's name: ");
    scanf("%s",xbox.name);
    printf("Enter their high score: ");
    scanf("%d",&xbox.highscore);
    printf("Enter the number of hours played: ");
    scanf("%f", &xbox.hours_played);

    printf("Player %s has a high score of %d and played %.2f hours\n",
            xbox.name,xbox.highscore, xbox.hours_played);
    return(0);
}

/*
```

2. Replace the name member in the human structure with a nested structure. Name that structure id and have it contain two members, char arrays,
first and last( or use dynamic memory allocation) for storing an individual's first and last names. When done, the reference to the president's
name will be variables president.name.first and president.name.last. Be sure to assign values to these variables in your code and 
display the results. 

```c
*/
#include <stdio.h>
#include <string.h>

int example2()
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    struct human
    {
        struct{
            char first[20];
            char last[25];
        } name;
        struct date birthday;
    };
    struct human president;

    strcpy(president.name.first, "George");
    strcpy(president.name.last, "Washington");
    president.birthday.month = 2;
    president.birthday.day = 22;
    president.birthday.year = 1732;

    printf("%s %s was born on %d/%d/%d\n",
            president.name.first,
            president.name.last,
            president.birthday.month,
            president.birthday.day,
            president.birthday.year);

    return(0);
}
/*
```
3. Define a struct type with the name Length that represents a length in yards, feet, and inches. Define an add() 
function that will add two Length arguments and return the sum as type Length. 
Define a second function, show(), that will display the value of its Length argument. 
Write a program that will use the Length type and the add() and show() functions to sum 
an arbitrary number of lengths in yards, feet, and 
inches that are entered from the keyboard and output the total length.
*/
struct Length
{
    float yards;
    float feet;
    int inches;
};

struct Length add(struct Length x, struct Length y)
{
    struct Length newLength;

    newLength.yards = x.yards + y.yards;
    newLength.feet = x.feet + y.feet;
    newLength.inches = x.inches + y.inches;
    
    return newLength;
}

int show(struct Length x)
{
    printf("%.2f yards, %.2f feet, or %d inches.\n", x.yards, x.feet, x.inches);
    return 0;
}

int example3(void)
{
    struct Length segment1, segment2, combined;

    printf("Enter the length, in inches, of the first segment: ");
    scanf("%d", &segment1.inches);

    printf("Enter the length, in inches, of the second segment: ");
    scanf("%d", &segment2.inches);

    segment1.feet = segment1.inches / 12.0;
    segment1.yards = segment1.feet / 3.0;
    segment2.feet = segment2.inches / 12.0;
    segment2.yards = segment2.feet / 3.0;
    
    combined = add(segment1, segment2);
    printf("\nThe total length of the the segments is ");
    show(combined);

    return 0;
}


/*
4. Define a struct type that contains a person's name consisting of a first name and a second name, 
plus the person's phone number. Use this struct in a program that will allow one or more names and 
corresponding numbers to be entered and will store the entries in an array of structures. 
The program should allow a second name to be entered and output 
all the numbers corresponding to the name, and optionally output all the names with their corresponding numbers.
*/
#include <stdlib.h>

struct Contact {
    char first_name[32];
    char second_name[32];
    char phone[16];
};

// int parse_phone(char * phonenumber){
//     char temp[16] = {0};
//     strcpy(temp, phonenumber);
//     char * temp_ptr = &temp;
//     while (temp_ptr != NULL){
//         if (strlen(phonenumber) < 8){

//         }
//     }
// }

int example4(void)
{
    struct Contact * contactList_ptr = malloc(100 * sizeof(struct Contact));
    struct Contact * work_ptr = contactList_ptr;

    char * firstNames[10] = {"James", "John", "Jim", "Joe", "Jason", "Dave", "Derrick", "Bob", "Tom", "Jack"};
    char * secondNames[4] = {"some_Company", "my_family", "1337_H@x0r", "SME"};
    char * phoneNumbers[10] = {"012-345-6789", "1234567890", "2345678901", "3456789012", "4567890123", "5678901234", "6789012345", "7890123456", "8901234567", "9012345678"};

    
    for (int i = 0; i < 10; i++){
        strcpy(work_ptr->first_name, firstNames[i]);
        if (i < 3){
            strcpy(work_ptr->second_name, secondNames[0]);
        }
        else if (i < 5){
            strcpy(work_ptr->second_name, secondNames[1]);
        }
        else if (i < 6){
            strcpy(work_ptr->second_name, secondNames[2]);
        }
        else if (i < 7){
            strcpy(work_ptr->second_name, secondNames[3]);
        }
        strcpy(work_ptr->phone, phoneNumbers[i]);
        work_ptr++;
    }

    // free(work_ptr);

    for (work_ptr = contactList_ptr; *work_ptr->first_name != '\0'; work_ptr++){
        printf("Name: %s\tSecond: %s\tPhone: %s\n", work_ptr->first_name, work_ptr->second_name, work_ptr->phone);
    }

    free(contactList_ptr);
    return 0;
}

/*
5. Write a program to compute the weekly pay for 10 machine shop workers with a 6 character ID, a 20 character name,
the hours worked, and the hourly rate of pay. Compute the gross pay with 25% deductions from the gross pay for the net pay.
Output the ID, name, hours worked, hourly rate of pay, gross pay, deductions, and net pay. The overtime pay rate over 40 hours
is 1.5 times the hourly rate of pay. Organize the data by employee.
*/
#define EmpIDSize 7

struct MachineShopWorker
{
    char id[EmpIDSize];
    char name[20];
    float hours_worked;
    float hourly_pay;
    float gross_pay;
    float deductions;
    float net_pay;
};

float calc_grosspay(struct MachineShopWorker emp)
{
    if (emp.hours_worked > 40.0){
        return (40 * emp.hourly_pay) + ((emp.hours_worked - 40.0) * (emp.hourly_pay * 1.5)); 
    }
    else{
        return emp.hours_worked * emp.hourly_pay;
    }
}

float calc_deductions(struct MachineShopWorker emp)
{
    return emp.gross_pay * 0.25;
}

float calc_netpay(struct MachineShopWorker emp)
{
    return emp.gross_pay - emp.deductions;
}

int show_empData(struct MachineShopWorker emp)
{
    printf("\n\tID: %s\n\tName: %s\n\tHours Worked: %.2f\n\tHourly Pay Rate: %.2f\n\tGross Pay: %.2f\n\tDeductions: -%.2f\n\tNet Pay: %.2f\n", 
                emp.id, emp.name, emp.hours_worked, emp.hourly_pay, emp.gross_pay, emp.deductions, emp.net_pay);

    return 0;
}

int example5(void)
{
    char * employeeIds[10] = {"msw100", "msw101", "msw102", "msw103", "msw104", "msw105", "msw106", "msw107", "msw108", "msw109"};
    char * employeeNames[10] = {"James", "John", "Jim", "Joe", "Jason", "Dave", "Derrick", "Bob", "Tom", "Jack"};
    float hourlyPay[10] = {10.5, 12.2, 9.75, 10.25, 10.75, 11.3, 11.7, 11.5, 11.0, 10.8};
    struct MachineShopWorker emp01; //= {*employeeIds[0], *employeeNames[0], 0, hourlyPay[0], 0, 0, 0};
    struct MachineShopWorker emp02; //= {*employeeIds[1], *employeeNames[1], 0, hourlyPay[1], 0, 0, 0};
    struct MachineShopWorker emp03; //= {*employeeIds[2], *employeeNames[2], 0, hourlyPay[2], 0, 0, 0};
    struct MachineShopWorker emp04; //= {*employeeIds[3], *employeeNames[3], 0, hourlyPay[3], 0, 0, 0};
    struct MachineShopWorker emp05; //= {*employeeIds[4], *employeeNames[4], 0, hourlyPay[4], 0, 0, 0};
    struct MachineShopWorker emp06; //= {*employeeIds[5], *employeeNames[5], 0, hourlyPay[5], 0, 0, 0};
    struct MachineShopWorker emp07; //= {*employeeIds[6], *employeeNames[6], 0, hourlyPay[6], 0, 0, 0};
    struct MachineShopWorker emp08; //= {*employeeIds[7], *employeeNames[7], 0, hourlyPay[7], 0, 0, 0};
    struct MachineShopWorker emp09; //= {*employeeIds[8], *employeeNames[8], 0, hourlyPay[8], 0, 0, 0};
    struct MachineShopWorker emp10; //= {*employeeIds[9], *employeeNames[9], 0, hourlyPay[9], 0, 0, 0};
    struct MachineShopWorker * database[10] = {&emp01, &emp02, &emp03, &emp04, &emp05, &emp06, &emp07, &emp08, &emp09, &emp10};

    for (int i = 0; i < 10; i++){
        strncpy((*database[i]).id, employeeIds[i], EmpIDSize);
        strcpy((*database[i]).name, employeeNames[i]);
        (*database[i]).hourly_pay = hourlyPay[i];
        printf("Enter the amount of hours %s (ID: %s) worked this week: ", (*database[i]).name, (*database[i]).id);
        scanf("%f", &(*database[i]).hours_worked);
        (*database[i]).gross_pay = calc_grosspay(*database[i]);
        (*database[i]).deductions = calc_deductions(*database[i]);
        (*database[i]).net_pay = calc_netpay(*database[i]);
    }

    printf("------------------------------------");
    for (int i = 0; i < 10; i++){
        show_empData(*database[i]);
        printf("------------------------------------");
    }
    printf("\n");
    return 0;
}

int main(void)
{
    // example1();
    // example2();
    // example3();
    example4();
    // example5();
    
    return(0);
}