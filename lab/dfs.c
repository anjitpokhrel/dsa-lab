
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[10];
int visited[10] = {0};

void insert(int u, int v)
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    newnode->vertex = v;
    newnode->next = adj[u];
    adj[u] = newnode;
}

void DFS(int vertex)
{
    struct node *temp;

    visited[vertex] = 1;

    printf("%d ", vertex);

    temp = adj[vertex];

    while (temp != NULL)
    {
        if (visited[temp->vertex] == 0)
        {
            DFS(temp->vertex);
        }

        temp = temp->next;
    }
}

int main()
{
    int n, e, u, v, start, i;

    printf("Student Name: [Your Name]\n");
    printf("File Path: [Your File Path]\n");

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges:\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d%d", &u, &v);

        insert(u, v);
        insert(v, u);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}
