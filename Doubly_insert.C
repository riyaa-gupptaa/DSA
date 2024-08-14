#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

void createDLL() {
    struct node *newnode;
    head = 0;
    int choice = 1;
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue? (0/1)\n");
        scanf("%d", &choice);
    }
}

void Atbeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data at beginning: \n");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) {
        head->prev = newnode;
    } else {
        tail = newnode; // if the list was empty, tail should also point to the new node
    }
    head = newnode;
}

void Atend() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data at end: \n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = tail;
    if (tail != NULL) {
        tail->next = newnode;
    } else {
        head = newnode; // if the list was empty, head should also point to the new node
    }
    tail = newnode;
}

void insertAtPos() {
    int pos, i = 1;
    printf("Enter position: \n");
    scanf("%d", &pos);
    if (pos <= 0) {
        printf("Invalid Position\n");
        return;
    } else if (pos == 1) {
        Atbeg();
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        printf("Enter data: \n");
        scanf("%d", &newnode->data);
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            free(newnode);
        } else {
            newnode->next = temp->next;
            newnode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newnode;
            } else {
                tail = newnode; // update tail if newnode is added at the end
            }
            temp->next = newnode;
        }
    }
}

void insertAfterPos() {
    int pos, i = 1;
    printf("Enter position: \n");
    scanf("%d", &pos);
    if (pos <= 0) {
        printf("Invalid Position\n");
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        printf("Enter data: \n");
        scanf("%d", &newnode->data);
        while (i < pos && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range\n");
            free(newnode);
        } else {
            newnode->next = temp->next;
            newnode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newnode;
            } else {
                tail = newnode; // update tail if newnode is added at the end
            }
            temp->next = newnode;
        }
    }
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    createDLL();
    display();

    printf("Inserting at the beginning...\n");
    Atbeg();
    display();

    printf("Inserting at the end...\n");
    Atend();
    display();

    printf("Inserting at a specific position...\n");
    insertAtPos();
    display();

    printf("Inserting after a specific position...\n");
    insertAfterPos();
    display();

    return 0;
}
