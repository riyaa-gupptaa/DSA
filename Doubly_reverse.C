#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *tail = NULL;
void createDLL()
{
    struct node *newnode;
    head = 0;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue? (0/1)\n");
        scanf("%d", &choice);
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void reverseDLL()
{
    struct node *current, *nextnode;
    current = head;
    while (current != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;
}
int main(void)
{
    createDLL();
    display();
    printf("After Reversal\n");
    reverseDLL();
    display();
}