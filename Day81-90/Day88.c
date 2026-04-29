#include <stdio.h>

#define MAX 100

void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int canPlace(int arr[], int n, int k, int dist)
{
    int count = 1;
    int last = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] - last >= dist)
        {
            count++;
            last = arr[i];
        }

        if(count >= k)
            return 1;
    }

    return 0;
}

int main()
{
    int n, k;
    int arr[MAX];

    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    if(n <= 0 || n > MAX || k <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter stall positions:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    int left = 1;
    int right = arr[n - 1] - arr[0];
    int ans = 0;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(canPlace(arr, n, k, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("Maximum minimum distance:\n");
    printf("%d\n", ans);

    return 0;
}