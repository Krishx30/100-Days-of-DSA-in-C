#include <stdio.h>

#define MAX 100
#define INF 1000000

int main()
{
    int n, m;
    int graph[MAX][MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    if(n <= 0 || n > MAX || m < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if(u >= 1 && u <= n && v >= 1 && v <= n)
        {
            graph[u-1][v-1] = w;
            graph[v-1][u-1] = w;
        }
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    if(src < 1 || src > n)
    {
        printf("Invalid source\n");
        return 0;
    }

    int dist[MAX], visited[MAX];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src-1] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int u = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}