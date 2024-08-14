#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*tail=NULL;
void createDLL()
{
    struct node *newnode;
    head=0;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do you want to continue? (0/1)\n");
        scanf("%d", &choice);
    }
}
void delfromBeg()
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("List is Empty\n");
    }
    else if(head==tail)
    {
        head=tail=0;
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
}
void delfromEnd()
{
    struct node *temp;
    temp=tail;
    if(tail==0)
    {
        printf("List is empty\n");
    }
    else if(head==tail)
    {
        head=tail=0;
        free(temp);
    }
    else{
        temp=tail;
        tail->prev->next=0;
        free(temp);
    }
}
void delfrompos()
{
    int pos;
    int i=1;
    struct node *temp;
    temp=head;
    printf("Enter position: \n");
    scanf("%d",&pos);
    if(pos==1)
    {
        delfromBeg();
    }
    else if(temp->next==0)
    {
        tail=tail->prev;
        tail->next=0;
        free(temp);
    }
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main(void)
{
    createDLL();
    display();
    printf("Deletion from beginning\n");
    delfromBeg();
    display();
    printf("Deletion from End\n");
    delfromEnd();
    display();
    printf("Deletion from postion\n");
    delfrompos();
    display();
}