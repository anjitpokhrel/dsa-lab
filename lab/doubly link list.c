
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertBeginning()
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
}

void deleteEnd()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (head->next == NULL)
    {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Deleted: %d\n", temp->data);

    temp->prev->next = NULL;

    free(temp);
}

void display()
{
    struct node *temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
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
        printf("2. Delete End\n");
        printf("3. Display\n4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertBeginning(); break;
            case 2: deleteEnd(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
