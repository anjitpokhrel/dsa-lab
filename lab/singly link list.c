
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeginning()
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insertEnd()
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

void insertPosition()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

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
        printf("\n1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Display\n5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
