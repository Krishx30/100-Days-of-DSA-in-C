#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int size;

int hash(int key)
{
    return key % size;
}

void insert(int key)
{
    int index = hash(key);

    for(int i = 0; i < size; i++)
    {
        int newIndex = (index + i * i) % size;

        if(table[newIndex] == -1)
        {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

int search(int key)
{
    int index = hash(key);

    for(int i = 0; i < size; i++)
    {
        int newIndex = (index + i * i) % size;

        if(table[newIndex] == -1)
            return 0;

        if(table[newIndex] == key)
            return 1;
    }

    return 0;
}

int main()
{
    int n;
    char op[20];
    int key;

    printf("Enter table size: ");
    scanf("%d", &size);

    printf("Enter number of operations: ");
    scanf("%d", &n);

    if(size <= 0 || size > MAX || n < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    for(int i = 0; i < size; i++)
        table[i] = -1;

    for(int i = 0; i < n; i++)
    {
        printf("Enter operation: ");
        scanf("%s", op);

        if(strcmp(op, "INSERT") == 0)
        {
            printf("Enter value: ");
            scanf("%d", &key);
            insert(key);
        }
        else if(strcmp(op, "SEARCH") == 0)
        {
            printf("Enter value: ");
            scanf("%d", &key);

            if(search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}