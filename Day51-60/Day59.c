#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

int postIndex;

struct Node* createNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* build(int inorder[], int postorder[], int start, int end)
{
    if(start > end)
        return NULL;

    struct Node* root = createNode(postorder[postIndex--]);

    if(start == end)
        return root;

    int index = search(inorder, start, end, root->data);

    root->right = build(inorder, postorder, index + 1, end);
    root->left = build(inorder, postorder, start, index - 1);

    return root;
}

void preorder(struct Node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    int inorder[MAX], postorder[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter inorder traversal:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &postorder[i]);
    }

    postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1);

    printf("Preorder traversal:\n");
    preorder(root);

    printf("\n");

    return 0;
}