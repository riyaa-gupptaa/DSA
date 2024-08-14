#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*tail;
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
void insertAtbeg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
void insertAtend()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newnode->data);
    if(tail==0)
    {
        tail=newnode;
        newnode->next=tail;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insertAtpos()
{
    struct node *newnode,*temp;
    int pos,i=1;
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos<0)
    {
        printf("Invalid position");
    }
    else if(pos==1)
    {
        insertAtbeg();
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=tail->next;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
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
int main(void)
{
    createCLL();
    display();
    printf("After inserting at the beginning\n");
    insertAtbeg();
    display();
    printf("After inserting at the end\n");
    insertAtend();
    display();
    printf("After inserting at a position\n");
    insertAtpos();
    display();
}