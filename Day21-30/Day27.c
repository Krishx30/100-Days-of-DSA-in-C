#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return head;
}

struct Node *reverseList(struct Node *head)
{
    struct Node *temp = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
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
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    struct Node *head = createList(n);

    head = reverseList(head);

    printf("Reversed Doubly Linked List:\n");
    printList(head);

    return 0;
}