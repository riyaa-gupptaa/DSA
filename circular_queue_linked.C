#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;
void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(rear==0)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        front=rear=0;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void Peek()
{
    if(front==0 && rear==0)
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("%d\n",front->data);
    }
}
void display()
{
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Queue is Empty\n");
    }
    else{
        while(temp->next!=front)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int main(void)
{
    enqueue(5);
    enqueue(2);
    enqueue(7);
    enqueue(4);
    display();
    Peek();
    dequeue();
    display();
}