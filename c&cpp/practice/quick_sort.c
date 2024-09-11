#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}
int partition(int a[], int low, int high) {
    int pivot, temp, i, j;
    pivot = a[low];
    i = low;
    j = high + 1;

    while (i <= j) {
        do {
            i++;
        } while (a[i] <= pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

int main() {
    int a[10000], i, j, n = 5000;
    double total_time = 0.0;
    clock_t start, end;
    FILE *fp;
    fp = fopen("quicksort.txt", "w");
    srand(time(NULL));
    for (j = 1; j <= 10; j++) {
        printf("\n n=%d\n", n);
        for (i = 0; i < n; i++) {
            a[i] = rand() % 10000;
        }
        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();
        total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fp, "%d\t%lf\n", n, total_time);
        printf("\n Time taken is: %f sec\n", total_time);
        n = n + 500;
    }
    fclose(fp);
    return 0;
}