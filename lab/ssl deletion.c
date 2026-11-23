
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
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void deleteNode()
{
    struct node *temp, *prev;
    int value;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Node deleted successfully.\n");
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
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
