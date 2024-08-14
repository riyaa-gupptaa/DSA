#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=0;
void Push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void display()
{
    struct node*temp;
    temp=top;
    if(top==0)
    {
        printf("List is Empty\n");
    }
    else{
        while(temp!=0)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void Peek()
{
    if(top==0)
    {
        printf("List is Empty\n");
    }
    else{
        printf("Top element is %d\n",top->data);
    }
}
void Pop()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        printf("Stack is Empty\n");
    }
    else{
        printf("%d\n",top->data);
        top=top->next;
        free(temp);
    }
}
int main(void)
{
    Push(2);
    Push(3);
    Push(10);
    display();
    Peek();
    Pop();
    Peek();
    display();
}