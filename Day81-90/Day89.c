#include <stdio.h>

#define MAX 100

int canAllocate(int arr[], int n, int m, int maxPages)
{
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxPages)
            return 0;

        if(pages + arr[i] > maxPages)
        {
            students++;
            pages = arr[i];
        }
        else
        {
            pages += arr[i];
        }
    }

    return students <= m;
}

int main()
{
    int n, m;
    int arr[MAX];

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    if(n <= 0 || n > MAX || m <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter pages in books:\n");
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

        if(canAllocate(arr, n, m, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("Minimum pages:\n");
    printf("%d\n", ans);

    return 0;
}