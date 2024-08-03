#include <stdio.h>

int main() {
    printf("This program keeps track of your monthly budget\n");
    printf("Please enter the following:\n");
    float mi, bl, ale, atw, ato, aoe;
    printf("\tYour monthly income: ");
    scanf("%f", &mi);
    printf("\tYour budgeted living expenses: ");
    scanf("%f", &bl);
    printf("\tYour actual living expenses: ");
    scanf("%f", &ale);
    printf("\tYour actual taxes withheld: ");
    scanf("%f", &atw);
    printf("\tYour actual tithe offerings: ");
    scanf("%f", &ato);
    printf("\tYour actual other expenses: ");
    scanf("%f", &aoe);

    printf("\nThe following is a report on your monthly expenses\n");
    printf("Item                 Budget    Actual\n");
    printf("=================  ==========  ==========\n");
    printf("Income             $ 1000.00   $ %.2f\n", mi);
    printf("Taxes              $  100.00   $ %.2f\n", atw);
    printf("Tithing            $  100.00   $ %.2f\n", ato);
    printf("Living             $  650.00   $ %.2f\n", ale);
    printf("Other              $  150.00   $ %.2f\n", aoe);
    printf("=================  ==========  ==========\n");

    float diff = mi - atw - ato - ale - aoe;
    printf("Difference         $    0.00   $ %.2f", diff);

    return 0;
}
