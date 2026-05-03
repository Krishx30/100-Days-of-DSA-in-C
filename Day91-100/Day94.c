#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter non-negative elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 0)
        {
            printf("Invalid input\n");
            return 0;
        }
    }

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int *freq = malloc((max + 1) * sizeof(int));
    if (freq == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i <= max; i++)
        freq[i] = 0;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (int i = 1; i <= max; i++)
        freq[i] += freq[i - 1];

    int output[MAX];

    for (int i = n - 1; i >= 0; i--)
    {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(freq);

    return 0;
}
