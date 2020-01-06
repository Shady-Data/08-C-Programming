// Calculate mileage reimbursement

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char **argv){

    double startingMileage, endingMileage, ratePerMile;

    printf("Enter the starting mileage: ");
    scanf("%lf", &startingMileage);

    printf("Enter the ending mileage: ");
    scanf("%lf", &endingMileage);

    printf("Enter rate per mile: ");
    scanf("%lf", &ratePerMile);

    double totalMiles = endingMileage - startingMileage;
    double reimbursement = totalMiles * ratePerMile;
    reimbursement = round(reimbursement * 100)/100;

    printf("You drove %f miles, at %f per mile, you are owed $%.2f\n", totalMiles, ratePerMile, reimbursement);

    return 0;
}