#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

struct Node* createNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int dfs(int v, int parent)
{
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        int adjNode = temp->data;

        if(!visited[adjNode])
        {
            if(dfs(adjNode, v))
                return 1;
        }
        else if(adjNode != parent)
        {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    if(n <= 0 || n > MAX || m < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if(u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
    }

    int hasCycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}