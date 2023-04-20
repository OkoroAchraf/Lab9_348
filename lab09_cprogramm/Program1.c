#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

double* read_sales(const char* file){
    FILE* fp = fopen(file, "r");
    if(!fp){
        printf("Error: Unable to open file\n");
        exit(1);
    }

    double* sales = malloc(MONTHS * sizeof(double));
    int i = 0;
    while(fscanf(fp, "%lf", &sales[i])== 1 && i < MONTHS){
        i++;
    }
    fclose(fp);
    return sales;
}


void sales_report(double* sales){
    char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly sales report for 2022:\n\n");
    printf("Month       Sales\n");
    for(int i = 0; i < MONTHS; i++){
        printf("%-10s  $%.2f\n", months[i], sales[i]);
    }
}

void sales_summary(double* sales){
    double min = sales[0];
    double max = sales[0];
    double sum = 0;
    int min_index = 0;
    int max_index = 0;
    char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i = 0; i< MONTHS; i++){
        if(sales[i] < min){
            min = sales[i];
            min_index = i;
        }
        if(sales[i] > max){
            max = sales[i];
            max_index = i;
        }
        sum += sales[i];
    }

    printf("\nSales summary:\n\n");
    printf("Minimum sales: $%0.2lf (%s)\n", min, months[min_index]);
    printf("Maximum sales: $%0.2lf (%s)\n", max, months[max_index]);
    printf("Average sales: $%0.2lf\n\n", sum/MONTHS);
}

void moving_average(double* sales){

    printf("\nSix-Month Moving Average:\nStart Month  End Month  Average\n\n");

    char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    double moving_average [7] = {};

    int i = 0;

    int e = 5;

    for(int i = 0; i < 7; i++){

        int average = 0;

        for(int x = i; x < i+6; ++x){

            average += sales[x];

        }

        moving_average[i] = average / 6.0;

    }



    for(int i = 0; i < 7; i++){

        printf("%-10s -  %-10s  $%.2f\n", months[i], months[i + 5], moving_average[i]);

    }

}

void descending(double* sales) {

    printf("\n\nSales Report (Highest to Lowest):\n   Month     Sales\n\n");

    char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};

    for (int i = 0; i < MONTHS; i++) {

        for (int e = i + 1; e < MONTHS; e++) {

            if (sales[i] < sales[e]) {

                double a = sales[i];

                sales[i] = sales[e];

                sales[e] = a;

                char* b = months[i];
                months[i] = months[e];
                months[e] = b;

            }

        }

    }

    for (int i = 0; i < MONTHS; i++) {

        printf("%-10s  $%.2f\n", months[i], sales[i]);

    }

}

int main() {
    double* sales = read_sales("data.txt");
    sales_report(sales);
    sales_summary(sales);
    moving_average(sales);
    descending(sales);
    free(sales);
    return 0;
}