
#include <stdio.h>

int main()
{
    int graph[10][10];
    int visited[10] = {0};
    int queue[10];

    int n, start;
    int front = 0, rear = -1;
    int i, vertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while (front <= rear)
    {
        vertex = queue[front++];

        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    return 0;
}
