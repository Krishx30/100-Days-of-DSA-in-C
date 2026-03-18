#include <stdio.h>
#include <stdlib.h>

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

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear)
    {
        struct Node *temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[++rear] = temp->left;

        if (temp->right != NULL)
            queue[++rear] = temp->right;
    }
}

int main()
{
    int n;
    int arr[100];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
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

    printf("Level order traversal:\n");
    levelOrder(root);

    printf("\n");

    return 0;
}