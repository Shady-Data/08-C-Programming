/* code pulled from Python
* # This program uses recursion to print numbers
* # from the Fibonnaci series
* 
* def main():
*     print('The first 10 numbers in the')
*     print('Fibonnaci Series are:')
* 
*     for number in range(0, 10):
*         print(fibonnaci(number))
* 
* def fibonnaci(n):
*     if n == 0:
*         return 0
*     elif n == 1:
*         return 1
*     else:
*         return fibonnaci(n - 1) + fibonnaci(n - 2)
* 
* # print(fibonnaci(3))
* 
* # Call the main function
*/

#include <stdio.h>
#include <time.h>

unsigned long long fibonnaci(unsigned long long n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else
    {
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }
    
}

void main()
{
    int num = 0;
    unsigned long long n = 0, result = 0;

    clock_t start, end;
    double time_taken = 0.0;
    printf("How many Fibonnaci sequences do you want to run\n");
    fscanf(stdin, "%d", &num);
    printf("\n");

    for (n = 0; n <= num; n++)
    {
        start = clock();
        result = fibonnaci(n);
        end = clock();

        time_taken = ((double)end - start)/CLOCKS_PER_SEC;
        printf("Fibonnaci C took %.6f seconds for n = %llu: result = %llu\n", time_taken, n, result);
    }
    printf("\n");
}