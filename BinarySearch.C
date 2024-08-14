#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements in a sorted manner\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter element\n");
        scanf("%d",&a[i]);
    }
    int beg=0;
    int end=n;
    int data;
    printf("Enter the data to be searched\n");
    scanf("%d",&data);
    while(beg<=end)
{
    int mid=(beg+end)/2;
    if(a[mid]==data)
    {
        printf("Element found at position: %d\n",mid);
        break;
    }
    else if(data<a[mid])
    {
        end=mid-1;
    }
    else{
        beg=mid+1;
    }
}
    return -1;
}