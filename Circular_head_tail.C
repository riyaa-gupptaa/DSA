#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=0,*tail=0;
void createCLL()
{
    struct node *newnode;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
        printf("Do you want to continue(0/1)?\n");
        scanf("%d",&choice);
    }
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    temp = head;
    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main(void)
{
    createCLL();
    display();
    return 0;
}