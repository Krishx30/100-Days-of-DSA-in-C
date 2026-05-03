#include <stdio.h>

#define MAX 100

void insertionSort(float arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    float arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter float values (0 to 1):\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
        if(arr[i] < 0 || arr[i] >= 1)
        {
            printf("Invalid input\n");
            return 0;
        }
    }

    float buckets[MAX][MAX];
    int count[MAX];

    for(int i = 0; i < n; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
    {
        int index = (int)(arr[i] * n);
        buckets[index][count[index]++] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(count[i] > 0)
            insertionSort(buckets[i], count[i]);
    }

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            arr[k++] = buckets[i][j];
        }
    }

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}