
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        struct node *newnode;
        newnode = malloc(sizeof(struct node));

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
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
    struct node *root = NULL;
    int n, value, i;

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("BST Inorder Traversal: ");
    inorder(root);

    return 0;
}
