#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int array[],int low,int high)
{
    int pivot=array[low];
    int left=low+1;
    int right=high;
    while(1)
    {
        while(left<=right && array[left]<=pivot)
        {
            left++;
        }
        while(left<=right && array[right]>pivot)
        {
            right--;
        }
        if(left>right)
        {
            break;
        }
        swap(&array[left],&array[right]);
    }
    swap(&array[low],&array[right]);
    return right;
}
void quick_sort(int array[],int low,int high)
{
    if(low<high)
    {
        int pivot_index=partition(array,low,high);
        quick_sort(array,low,pivot_index-1);
        quick_sort(array,pivot_index+1,high);
    }
}
void print_array(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}