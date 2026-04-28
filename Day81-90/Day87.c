#include <stdio.h>

#define MAX 100

int main()
{
    int n, key;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int left = 0, right = n - 1;
    int found = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
        {
            found = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (found != -1)
        printf("Element found at index: %d\n", found);
    else
        printf("Element not found\n");

    return 0;
}