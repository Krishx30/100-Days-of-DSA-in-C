#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

struct Node *reverseK(struct Node *head, int k)
{
    if (head == NULL)
        return NULL;

    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    int count = 0;

    // Reverse first k nodes
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse remaining list
    if (next != NULL)
        head->next = reverseK(next, k);

    return prev;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    struct Node *head = createList(n);

    printf("Enter value of k: ");
    scanf("%d", &k);

    head = reverseK(head, k);

    printf("List after reversing in groups:\n");
    printList(head);

    return 0;
}