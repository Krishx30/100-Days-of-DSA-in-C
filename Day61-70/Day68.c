#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];

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

    indegree[v]++;
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
        indegree[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if(u >= 0 && u < n && v >= 0 && v < n)
            addEdge(u, v);
    }

    int queue[MAX];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[++rear] = i;
    }

    printf("Topological Order:\n");

    int count = 0;

    while(front <= rear)
    {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        struct Node* temp = adj[v];

        while(temp != NULL)
        {
            indegree[temp->data]--;

            if(indegree[temp->data] == 0)
                queue[++rear] = temp->data;

            temp = temp->next;
        }
    }

    if(count != n)
        printf("\nCycle detected, topological sort not possible");

    printf("\n");

    return 0;
}