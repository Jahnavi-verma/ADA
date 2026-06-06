#include <stdio.h>
#include <stdlib.h>

#define max 100

float knapsack(float capacity, float weight[max], float profit[max], float ratio[max], int n) {
    int i = 0;
    float total_profit = 0;

    while (i < n && capacity > 0) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            total_profit += profit[i];
            i++;
        } else {
            total_profit += ratio[i] * capacity;
            break;
        }
    }

    return total_profit;
}

float weight[max], profit[max], ratio[max];

int main() {
    int n;
    float capacity;

    printf("enter number of objects:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("enter profit of obj %d:", i);
        scanf("%f", &profit[i]);
        printf("enter weight of obj %d:", i);
        scanf("%f", &weight[i]);
        ratio[i] = profit[i] / weight[i];
    }

    int swapped;
    float temp;

    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (ratio[i] < ratio[i + 1]) {
                temp = ratio[i];
                ratio[i] = ratio[i + 1];
                ratio[i + 1] = temp;

                temp = profit[i];
                profit[i] = profit[i + 1];
                profit[i + 1] = temp;

                temp = weight[i];
                weight[i] = weight[i + 1];
                weight[i + 1] = temp;

                swapped = 1;
            }
        }
    } while (swapped);

    printf("enter capacity:");
    scanf("%f", &capacity);

    float total_profit = knapsack(capacity, weight, profit, ratio, n);
    printf("Total profit = %.2f\n", total_profit);

    return 0;
}