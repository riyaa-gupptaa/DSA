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
int getlength()
{
    struct node *temp;
    int count = 0;

    if (tail == NULL)
    {
        printf("List is Empty\n");
        return count;
    }

    temp = tail->next;  // Initialize temp to the first node

    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);  // Loop until we reach the first node again

    printf("Length of the linked list is: %d\n", count);
    return count;
}
void delAtbeg()
{
    struct node *temp;
    temp=tail->next;
    if(tail==0)
    {
        printf("List is empty\n");
    }
    else if(temp->next==temp)
    {
        tail=0;
        free(temp);
    }
    else{
    tail->next=temp->next;
    free(temp);
    }
}
void delfromEnd()
{
    struct node *current,*prev;
    current=tail->next;
    if(tail==0)
    {
        printf("List is Empty\n");
    }
    else if(current->next==current)
    {
        tail=0;
        free(current);
    }
    else{
        while(current->next!=tail->next)
        {
            prev=current; 
            current=current->next;
        }
        prev->next=tail->next;
        tail=prev;
        free(current);
    }
}
void delfrompos()
{
    struct node *current,*nextnode;
    current=tail->next;
    int pos,i=1;
    int l=getlength();
    printf("Enter position\n");
    scanf("%d",&pos); 
    if(pos<1||pos>l)
    {
        printf("Invalid position");
    }
    if(pos==1)
    {
        delAtbeg();
    }
    else{
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }

}
int main(void)
{
    createCLL();
    display();
    getlength();
    printf("After deletion from beginning\n");
    delAtbeg();
    getlength();
    display();
    printf("After deletion from the end\n");
    delfromEnd();
    display();
    getlength();
    printf("After deletion from a postion\n");
    delfrompos();
    display();
}