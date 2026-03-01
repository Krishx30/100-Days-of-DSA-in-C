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

int getLength(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct Node *rotateRight(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int n = getLength(head);

    k = k % n;
    if (k == 0)
        return head;

    struct Node *temp = head;

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Make circular
    temp->next = head;

    int steps = n - k;
    struct Node *newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
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

    head = rotateRight(head, k);

    printf("Rotated List:\n");
    printList(head);

    return 0;
}