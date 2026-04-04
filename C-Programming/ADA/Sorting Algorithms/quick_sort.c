#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t start, end;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
  int n;
  printf("Enter the number of values to be inserted into the array: ");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
        arr[i] = rand() % (n * 2);

  start = clock();
  quicksort(arr, 0, n - 1);
  end = clock();

  printf("Time Taken (ms): %lf \n",
        (double)(end - start) / (double)(CLOCKS_PER_SEC)*1000);  

  return 0;
}
