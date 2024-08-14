#include<stdio.h>
#include<stdlib.h> 
int main(void)
{
    struct node{
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*temp;
    head=0;
    int choice=1;
    int count=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue(0/1)? ");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
    printf("%d",count);
    return 0;
}