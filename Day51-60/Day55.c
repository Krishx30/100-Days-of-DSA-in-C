#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node *nodes[n];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        if (nodes[i] != NULL)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

void rightView(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[MAX];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear)
    {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++)
        {
            struct Node *node = queue[front++];

            if (i == size - 1)
                printf("%d ", node->data);

            if (node->left)
                queue[++rear] = node->left;

            if (node->right)
                queue[++rear] = node->right;
        }
    }
}

int main()
{
    int n;
    int arr[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter level order elements (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    printf("Right view of tree:\n");
    rightView(root);

    printf("\n");

    return 0;
}