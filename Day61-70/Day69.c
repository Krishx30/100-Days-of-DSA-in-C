#include <stdio.h>

#define MAX 100
#define INF 1000000

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, minIndex = -1;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX];
    int visited[MAX];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] && dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source:\n");
    for(int i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main()
{
    int n, m, u, v, w, src;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    if(n <= 0 || n > MAX || m < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);

        if(u >= 0 && u < n && v >= 0 && v < n)
        {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    if(src < 0 || src >= n)
    {
        printf("Invalid source\n");
        return 0;
    }

    dijkstra(graph, n, src);

    return 0;
}