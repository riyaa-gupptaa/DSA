#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*tail=0;
void createCLL()
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
        printf("Do you want to continue(0/1)?\n");
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
         printf("%d\n",temp->data);
}
void reverse()
{
    struct node *current,*prev,*nextnode;
    current=tail->next;
    nextnode=current->next;
    if(tail==0)
    {
        printf("List is Empty\n");
    }
    else{
        while(current!=tail)
        {
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
}
int main(void)
{
    createCLL();
    display();
    printf("After reversing\n");
    reverse();
    display();
}