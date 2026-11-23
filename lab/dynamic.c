
#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int capacity = 2;

void push()
{
    int value;

    if (top == capacity - 1)
    {
        capacity = capacity * 2;
        stack = realloc(stack, capacity * sizeof(int));
        printf("Stack size increased.\n");
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("Element pushed successfully.\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    stack = (int *)malloc(capacity * sizeof(int));

    if (stack == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 4);

    free(stack);

    return 0;
}
