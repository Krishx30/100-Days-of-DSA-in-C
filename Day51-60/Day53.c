#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Pair
{
    struct Node *node;
    int hd;
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

void verticalOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Pair queue[MAX];
    int front = 0, rear = -1;

    int map[2 * MAX][MAX];
    int count[2 * MAX] = {0};

    int offset = MAX;

    queue[++rear].node = root;
    queue[rear].hd = 0;

    while (front <= rear)
    {
        struct Pair temp = queue[front++];
        struct Node *node = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = node->data;

        if (node->left)
        {
            queue[++rear].node = node->left;
            queue[rear].hd = hd - 1;
        }

        if (node->right)
        {
            queue[++rear].node = node->right;
            queue[rear].hd = hd + 1;
        }
    }

    for (int i = 0; i < 2 * MAX; i++)
    {
        if (count[i] > 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
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

    printf("Vertical order traversal:\n");
    verticalOrder(root);

    return 0;
}