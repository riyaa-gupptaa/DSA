#include <stdio.h>
#include <stdlib.h>
#define N 5
int S1[N], S2[N];
int top1 = -1, top2 = -1;
int count = 0;
void Push1(int data)
{
    if (top1 == N - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        top1++;
        S1[top1] = data;
    }
}
int Pop1()
{
    return S1[top1--];
}
int Pop2()
{
    return S2[top2--];
}
void Push2(int data)
{
    if (top2 == N - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top2++;
        S2[top2] = data;
    }
}
void display()
{
    int i;
    for (i = 0; i <= top1; i++)
    {
        printf("%d\n", S1[i]);
    }
}
void enqueue(int x)
{
    Push1(x);
    count++;
}
void dequeue()
{
    int i, a, b;
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = Pop1();
            Push2(a);
        }
        b = Pop2();
        printf("%d\n", b);
        count--;
        for (i = 0; i < count; i++)
        {
            a = Pop2();
            Push1(a);
        }
    }
}
int main(void)
{
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    dequeue();
    enqueue(7);
    display();
}