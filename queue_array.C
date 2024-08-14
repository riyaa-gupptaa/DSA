#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if(rear==N-1)
    {
        printf("Queue is full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(front==rear)
    {
        printf("%d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("%d\n",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        for(i=front;i<rear+1;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
void Peek()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("%d\n",queue[front]);
    }
}
int main(void)
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    Peek();
    dequeue();
    Peek();
    display();
}