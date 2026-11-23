
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);

        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    return head;
}

struct node *add(struct node *p, struct node *q)
{
    struct node *result = NULL, *temp, *newnode;

    while (p != NULL && q != NULL)
    {
        newnode = malloc(sizeof(struct node));

        if (p->exp == q->exp)
        {
            newnode->coeff = p->coeff + q->coeff;
            newnode->exp = p->exp;
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            newnode->coeff = p->coeff;
            newnode->exp = p->exp;
            p = p->next;
        }
        else
        {
            newnode->coeff = q->coeff;
            newnode->exp = q->exp;
            q = q->next;
        }

        newnode->next = NULL;

        if (result == NULL)
            result = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    while (p != NULL || q != NULL)
    {
        newnode = malloc(sizeof(struct node));

        if (q == NULL || (p != NULL && p->exp > q->exp))
        {
            newnode->coeff = p->coeff;
            newnode->exp = p->exp;
            p = p->next;
        }
        else
        {
            newnode->coeff = q->coeff;
            newnode->exp = q->exp;
            q = q->next;
        }

        newnode->next = NULL;

        if (result == NULL)
            result = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    return result;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        head = head->next;

        if (head != NULL)
            printf(" + ");
    }

    printf("\n");
}

int main()
{
    struct node *p, *q, *result;

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    printf("\nEnter first polynomial:\n");
    p = create();

    printf("\nEnter second polynomial:\n");
    q = create();

    printf("\nFirst Polynomial: ");
    display(p);

    printf("Second Polynomial: ");
    display(q);

    result = add(p, q);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
