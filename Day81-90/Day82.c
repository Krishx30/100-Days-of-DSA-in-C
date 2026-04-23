#include <stdio.h>

#define MAX 100

int lowerBound(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] >= x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int upperBound(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] > x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, x;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}