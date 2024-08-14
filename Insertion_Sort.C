#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the element\n");
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
       int temp=a[i];
       int j=i-1;
       while(j>=0 && a[j]>temp)
       {
        a[j+1]=a[j];
        j--;
       }
       a[j+1]=temp;
    }
    printf("After sorting, array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}