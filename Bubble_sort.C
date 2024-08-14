#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in the array\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the element\n");
        scanf("%d",&a[i]);
    }
    printf("After sorting elements\n");
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}