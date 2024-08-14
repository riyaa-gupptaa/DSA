#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void createDLL()
{
    struct node *newnode;
    struct node *temp;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head; // Point to itself to form a circular linked list
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->next = head; // Link the new node to the head to maintain the circular nature
            temp = newnode;
        }
        temp->next = head;
        printf("Do you want to continue(0/1)\n");
        scanf("%d", &choice);
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
    createDLL();
    printf("Display after creation\n");
    display();
}