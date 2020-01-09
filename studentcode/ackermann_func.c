/* code pulled from Python
* '''
* 8. Ackermann’s Function
*     Ackermann’s Function is a recursive mathematical algorithm that can be used to test how
*     well a system optimizes its performance of recursion. Design a function ackermann(m, n),
*     which solves Ackermann’s function. Use the following logic in your function:
*         If m = 0 then return n + 1
*         If n = 0 then return ackermann(m - 1, 1)
*         Otherwise, return ackermann(m - 1, ackermann(m, n - 1))
*     Once you’ve designed your function, test it by calling it with small values for m and n.
* '''
* import time
* 
* def main():
*     # values to pass to the ackermann function
*     num1 = int(input('Enter the first number to pass to Ackermann\'s function: '))
*     num2 = int(input('Enter the second number to pass to Ackermann\'s function: '))
* 
*     # start = time.time()
*     # call the Ackermann function and pass num1 and num2 as arguments
*     print(ackermann(num1, num2))
*     # stop = time.time()
*     # print('Time to complete:', stop - start)
* 
* # Define the ackerman function
* # parameters: int p_m, int p_n
* def ackermann(p_m, p_n):
*     # base case: if m == 0 return n + 1
*     if p_m == 0:
*         return p_n + 1
*     # recursive case 1: if n == 0 call ackermann(m - 1, 1)
*     elif p_n == 0:
*         return ackermann(p_m - 1, 1)
*     # recursive case 2: return ackermann(m- 1 (ackermann(m, n - 1))
*     else:
*         return ackermann(p_m - 1, ackermann(p_m, p_n - 1))
*/

#include <stdio.h>
#include <time.h>

int ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

void main()
{
    int num1 = 0;
    int num2 = 0;
    printf("Enter the first number for the Ackermann function: ");
    fgets("", num1, stdin);
    printf("Enter the second number for the Ackermann function: ");
    fgets("", num2, stdin);

    clock_t start, end;
    double time_taken = 0.0;

    start = clock();
    ackermann(num1, num2);
    end = clock();

    time_taken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\n\nC took %.10f seconds for an Ackermann function of m = %d and n = %d\n\n", time_taken, num1, num2);

}