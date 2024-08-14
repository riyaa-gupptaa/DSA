#include<stdio.h>
int main()
{
    int n;
    int found=0;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter a number\n");
        scanf("%d",&a[i]);
    }
    int data;
    printf("Enter the element to be searched\n");
    scanf("%d",&data);
    for(int i=0;i<n;i++)
    {
        if(a[i]==data)
        {
            printf("Element to be searched is at %d\n",i);
            found=1;
            break;
        }
    }
    if(found==0)
    {
        printf("Element not found\n");
    }
}