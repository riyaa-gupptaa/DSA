#include <stdio.h>
#include <stdlib.h>
#define N 6
int deque[N];
int f = -1, R = -1;
void enqueuefront(int x)
{
    if ((f == 0 && R == N - 1) || (f == R + 1))
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && R == -1)
    {
        f = R = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = N - 1;
        deque[f] = x;
    }
    else
    {
        f--;
        deque[f] = x;
    }
}
void enqueuerear(int x)
{
    if ((f == 0 && R == N - 1) && (f = R + 1))
    {
        printf("Queue is Full\n");
    }
    else if (f == -1 && R == -1)
    {
        f = R = 0;
        deque[R] = x;
    }
    else if (R == N - 1)
    {
        R = 0;
        deque[R] = x;
    }
    else
    {
        R++;
        deque[R] = x;
    }
}
void display()
{
    int i = f;
    if (f == -1 && R == -1)
    {
        printf("Queue is Empty\n");
    }
    while (i != R)
    {
        printf("%d\n", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[R]);
}
void getFront()
{
    printf("%d\n", deque[f]);
}
void dequefront()
{
    if (f == -1 && R == -1)
    {
        printf("Underflow Condition\n");
    }
    else if (f == R)
    {
        f = R = -1;
    }
    else if (f == N - 1)
    {
        printf("%d\n", deque[f]);
        f = 0;
    }
    else
    {
        printf("%d\n", deque[f]);
        f++;
    }
}
void dequerear()
{
    if (f == -1 && R == -1)
    {
        printf("Empty Queue\n");
    }
    else if (f == R)
    {
        f = R = -1;
    }
    else if (R == 0)
    {
        R = N - 1;
    }
    else{
        printf("%d\n",deque[R]);
        R--;
    }
}
int main(void)
{
    enqueuefront(2);
    enqueuefront(5);
    enqueuerear(-1);
    enqueuerear(0);
    enqueuefront(7);
    enqueuefront(4);
    display();
    dequerear();
    dequefront();
    dequerear();
}