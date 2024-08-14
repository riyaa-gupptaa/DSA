#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;
void Push()
{
    int x;
    printf("Enter data\n");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("Overflow Condition");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void Pop()
{
    int item;
    if(top==-1)
    {
        printf("Underflow Condition\n");
    }
    else{
        item=stack[top];
        top--;
        printf("Item removed is: %d\n",item);
    }
}
void Peek()
{
    if(top==-1)
    {
        printf("Stack is Empty\n");
    }
    else{
        printf("The element at the top is %d\n",stack[top]);
    }
}
void display()
{
    int i;
    printf("Elements in the stack are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
int main(void)
{
    int ch;
        do{
            printf("Enter choice: 1:Push 2:Pop 3:Peek 4:Display\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                Push();
                break;
                case 2:
                Pop();
                break;
                case 3:
                Peek();
                break;
                case 4:
                display();
                break;
                default:
                printf("Invalid Choice\n");
            }
        }
            while(ch!=0);
}