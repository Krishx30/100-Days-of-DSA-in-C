#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

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
        adj[i] = NULL;

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if(u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
    }

    printf("Adjacency List:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        struct Node* temp = adj[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}