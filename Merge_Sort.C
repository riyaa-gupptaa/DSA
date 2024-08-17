#include<stdio.h>
void merge(int array[], int lb, int mid, int Ub) {
    int n1 = mid - lb + 1;
    int n2 = Ub - mid;

    // Create temp arrays
    int left[n1], right[n2];

    // Copy data to temp arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = array[lb + i];
    for (int j = 0; j < n2; j++)
        right[j] = array[mid + 1 + j];

    // Merge the temp arrays back into array[lb..Ub]
    int i = 0;
    int j = 0;
    int k = lb;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }
}
void MergeSort(int array[], int lb, int Ub) {
    if (lb < Ub) {
        int mid = (lb + Ub) / 2;
        MergeSort(array, lb, mid);
        MergeSort(array, mid + 1, Ub);
        merge(array, lb, mid, Ub);
    }
}
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array is: ");
    print_array(arr, n);
    MergeSort(arr, 0, n - 1);
    printf("Sorted Array is: ");
    print_array(arr, n);
}
