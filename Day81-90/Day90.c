#include <stdio.h>

#define MAX 100

int canPaint(int arr[], int n, int k, int maxTime)
{
    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxTime)
            return 0;

        if(time + arr[i] > maxTime)
        {
            painters++;
            time = arr[i];
        }
        else
        {
            time += arr[i];
        }
    }

    return painters <= k;
}

int main()
{
    int n, k;
    int arr[MAX];

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    if(n <= 0 || n > MAX || k <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter board lengths:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left = arr[0];
    int right = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > left)
            left = arr[i];
        right += arr[i];
    }

    int ans = right;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(canPaint(arr, n, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("Minimum time:\n");
    printf("%d\n", ans);

    return 0;
}