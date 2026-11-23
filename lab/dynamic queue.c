
#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = 0, rear = -1;
int capacity = 2;

void enqueue()
{
    int value;

    if (rear == capacity - 1)
    {
        capacity = capacity * 2;

        queue = realloc(queue, capacity * sizeof(int));

        if (queue == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        printf("Queue size increased.\n");
    }

    printf("Enter value: ");
    scanf("%d", &value);

    rear++;
    queue[rear] = value;

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    if (front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if (front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    queue = malloc(capacity * sizeof(int));

    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 4);

    free(queue);

    return 0;
}
