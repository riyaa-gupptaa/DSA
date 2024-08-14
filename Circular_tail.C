#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*tail=0;
void createDLL()
{
    struct node *newnode;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do you want to continue?(0/1)\n");
        scanf("%d",&choice);
    }
}
void display()
{
    struct node *temp;
    temp=NULL;
    if (tail == NULL)
    {
        printf("List is Empty\n");
    }
    else{
         temp=tail->next;
    }
         while(temp->next!=tail->next)
         {
            printf("%d\n",temp->data);
            temp=temp->next;
         }
         printf("%d",temp->data);
}
int main(void)
{
    createDLL();
    display();
    return 0;
}