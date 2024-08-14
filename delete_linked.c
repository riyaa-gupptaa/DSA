#include<stdio.h>
#include<stdlib.h>
void at_beginning(void);
void at_end(void);
void at_position(void);
void display(void);
struct node{
    int data;
    struct node *next;
};
struct node *head,*temp,*prevnode,*nextnode,*newnode;
int count=0;
int main(void)
{
    int choice=1;
    head=0;
    int a;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        printf("Enter the data you want to insert: \n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        count++;
        printf("Do you want to continue (0/1)?: ");
        scanf("%d",&choice);
    }
    printf("Which operation you want to perform?\n press 1 ----> delete from the beginning\n press 2 ----> delete at the end\n press 3 ----> delete from a specific position\n press 4 ----> To Display the Linked list\n");
    scanf("%d", &a);
    switch(a)
    {
        case 1:
            at_beginning();
            display();
            break;
        case 2:
            at_end();
            display();
            break;
        case 3:
            at_position();
            display();
            break;
        case 4:
            display();
            break;
    }
    return 0;
}
void at_beginning(void)
{
    temp=head;
    head=head->next;
    free(temp);
    count--;
}
void at_end(void)
{
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
    }
    else{
        prevnode->next=0;
    }
    free(temp);
    count--;
}
void at_position(void) {
    int pos, i = 1;
    temp = head;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos <= 0||pos>count) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        at_beginning();
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Can't be modified\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    count--;
}
void display(void)
{
    temp = head;
    printf("Your Linked list is : \n");
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

