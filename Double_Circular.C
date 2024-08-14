#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
}*head,*tail;
void createDCLL()
{
    int choice=1;
    struct node *newnode;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("Do you want to continue(0/1)?\n");
        scanf("%d",&choice);
    }
}
void display()
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("List is Empty\n");
    }
    else{
        while(temp!=tail)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int main(void)
{
    createDCLL();
    display();
}