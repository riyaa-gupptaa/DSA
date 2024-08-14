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
void delfrombeg()
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("List is Empty\n");
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
    }
    else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}
void delfromEnd()
{
    struct node *temp;
    temp=tail;
    if(head==0)
    {
        printf("List is Empty\n");
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
    }
    else{
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
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
void delfromPos()
{
    struct node *temp;
    int pos,i=1,l;
    temp=head;
    printf("Enter position\n");
    scanf("%d",&pos);
    l=getlength();
    if(pos<1||pos>l)
    {
        printf("Invalid Position\n");
    }
    else if(pos==1)
    {
        delfrombeg();
    }
    else{
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp->next==head)
        {
            tail=temp->prev;
            free(temp);
        }
        else{
            free(temp);
        }
    }
}
int main(void)
{
    createDCLL();
    display();
    printf("Delete from beginning\n");
    delfrombeg();
    display();
    printf("Delete From End\n");
    delfromEnd();
    display();
    printf("Delete from a position\n");
    getlength();
    delfromPos();
    display();
}