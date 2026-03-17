#include <stdio.h>
#include <string.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (front == (rear + 1) % MAX);
}

void push_front(int value)
{
    if (isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = value;
}

void push_back(int value)
{
    if (isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
}

void pop_front()
{
    if (isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void pop_back()
{
    if (isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + MAX) % MAX;
    }
}

int getFront()
{
    if (isEmpty())
        return -1;
    return deque[front];
}

int getBack()
{
    if (isEmpty())
        return -1;
    return deque[rear];
}

int size()
{
    if (isEmpty())
        return 0;
    return (rear - front + MAX) % MAX + 1;
}

void clear()
{
    front = rear = -1;
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void reverse()
{
    if (isEmpty())
        return;

    int i = front, j = rear;

    while (i != j && (i + MAX - 1) % MAX != j)
    {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

void sort()
{
    int n = size();
    if (n <= 1)
        return;

    int arr[MAX], i = front, idx = 0;

    while (1)
    {
        arr[idx++] = deque[i];
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    // Simple bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    front = 0;
    rear = n - 1;

    for (int i = 0; i < n; i++)
        deque[i] = arr[i];
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Deque Operations ---\n");
        printf("1. push_front\n2. push_back\n3. pop_front\n4. pop_back\n");
        printf("5. front\n6. back\n7. size\n8. display\n");
        printf("9. clear\n10. reverse\n11. sort\n0. exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push_front(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            push_back(value);
            break;

        case 3:
            pop_front();
            break;

        case 4:
            pop_back();
            break;

        case 5:
            printf("Front: %d\n", getFront());
            break;

        case 6:
            printf("Back: %d\n", getBack());
            break;

        case 7:
            printf("Size: %d\n", size());
            break;

        case 8:
            display();
            break;

        case 9:
            clear();
            printf("Deque cleared\n");
            break;

        case 10:
            reverse();
            printf("Deque reversed\n");
            break;

        case 11:
            sort();
            printf("Deque sorted\n");
            break;

        case 0:
            return 0;
        }
    }
}