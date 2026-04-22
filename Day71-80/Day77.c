#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *next;
};

struct Node *adj[MAX];
int visited[MAX];

struct Node *createNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int v)
{
    visited[v] = 1;

    struct Node *temp = adj[v];

    while (temp != NULL)
    {
        if (!visited[temp->data])
            dfs(temp->data);

        temp = temp->next;
    }
}

int main()
{
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    if (n <= 0 || n > MAX || m < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
    }

    // start DFS from vertex 0
    dfs(0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}