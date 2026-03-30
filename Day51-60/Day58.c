#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int preIndex = 0;

struct Node *createNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node *build(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;

    struct Node *root = createNode(preorder[preIndex++]);

    if (start == end)
        return root;

    int index = search(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, index - 1);
    root->right = build(preorder, inorder, index + 1, end);

    return root;
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    int preorder[MAX], inorder[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    struct Node *root = build(preorder, inorder, 0, n - 1);

    printf("Postorder traversal:\n");
    postorder(root);

    printf("\n");

    return 0;
}