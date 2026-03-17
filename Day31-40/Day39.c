#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int index)
{
    while(1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void insert(int x)
{
    if(size == MAX)
    {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin()
{
    if(size == 0)
        return -1;

    int min = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int peek()
{
    if(size == 0)
        return -1;

    return heap[0];
}

int main()
{
    int N, x;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        printf("Enter operation: ");
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
        else if(strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}