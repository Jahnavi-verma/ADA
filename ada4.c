#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int low, int high, int arr[]);
int partition(int low, int high, int arr[]);

void quicksort(int low, int high, int arr[]) {
    if (low < high) {
        int p = partition(low, high, arr);
        quicksort(low, p - 1, arr);
        quicksort(p + 1, high, arr);
    }
}

int partition(int low, int high, int arr[]) {
    int i = low;
    int j = high + 1;
    int pivot = arr[low];
    int temp;

    while (i < j) {
        do {
            i++;
        } while (i <= high && arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[j];
    arr[j] = pivot;
    arr[low] = temp;
    return j;
}

void main() {
    clock_t start, end;
    double cpu_time_used;
    int n;

    printf("Enter number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    quicksort(0, n - 1, arr);
    end = clock();

    cpu_time_used = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000.0;

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nExecution time:%.5f ms\n", cpu_time_used);
}