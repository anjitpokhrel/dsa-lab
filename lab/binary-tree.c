
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int value;
    struct node *newnode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    newnode = malloc(sizeof(struct node));

    newnode->data = value;

    printf("Enter left child of %d:\n", value);
    newnode->left = create();

    printf("Enter right child of %d:\n", value);
    newnode->right = create();

    return newnode;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root;

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    printf("Create Binary Tree:\n");
    root = create();

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
