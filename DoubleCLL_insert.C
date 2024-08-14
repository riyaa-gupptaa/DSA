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
void insertAtbeg(){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    if(head==0)
    {
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        head=newnode;
        tail->next=newnode;
    }
}
void insertAtend()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    if(head==0)
    {
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }
    else{
        newnode->next=tail->next;
        newnode->prev=tail;
        tail->next=newnode;
        tail->prev=newnode;
        tail=newnode;
    }
}
int getlength()
{
    struct node *temp;
    temp=head;
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    count++;
    printf("Length of the linked list is: %d\n",count);
    return count;
}
void insertAtpos()
{
    struct node *newnode,*temp;
    int pos,i=1,l;
    temp=head;
    printf("Enter Position\n");
    scanf("%d",&pos);
    l=getlength();
    if(pos<0||pos>l)
    {
        printf("Invalid position\n");
    }
    else if(pos==1)
    {
        insertAtbeg();
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}
int main(void)
{
    createDCLL();
    display();
    printf("Insert At the beginning of the list\n");
    insertAtbeg();
    display();
    printf("Insert At the end of the list\n");
    insertAtend();
    display();
    printf("Insert At a position of the list\n");
    insertAtpos();
    display();
    return 0;
}