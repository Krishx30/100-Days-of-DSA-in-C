#include <stdio.h>

#define MAX 100

int main()
{
    int n, m;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    if(n <= 0 || n > MAX || m < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if(u >= 0 && u < n && v >= 0 && v < n)
        {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}