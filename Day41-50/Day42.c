#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    queue[++rear] = x;
}

int dequeue()
{
    if (front > rear)
        return -1;

    return queue[front++];
}

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;

    return stack[top--];
}

int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    while (front <= rear)
    {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while (top != -1)
    {
        enqueue(pop());
    }

    printf("Reversed queue:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");

    return 0;
}