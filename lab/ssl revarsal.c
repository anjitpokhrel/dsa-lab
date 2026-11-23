
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode;

    while (current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head = prev;

    printf("List reversed successfully.\n");
}

void display()
{
    struct node *temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    do
    {
        printf("\n1. Insert\n2. Reverse\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: reverse(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
