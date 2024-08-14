#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the element\n");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
            {
                int temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
    }
    printf("After sorting elements are: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}