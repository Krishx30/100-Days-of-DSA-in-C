#include <stdio.h>

#define MAX 100
#define INF 1000000

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m, src;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    if(n <= 0 || n > MAX || m < 0 || m > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    if(src < 0 || src >= n)
    {
        printf("Invalid source\n");
        return 0;
    }

    int dist[MAX];

    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(int j = 0; j < m; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    printf("Shortest distances from source:\n");
    for(int i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}