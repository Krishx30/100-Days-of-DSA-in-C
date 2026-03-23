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

struct Node *insert(struct Node *root, int x)
{
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

struct Node *LCA(struct Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main()
{
    int n, x, n1, n2;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    struct Node *lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("Lowest Common Ancestor: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}