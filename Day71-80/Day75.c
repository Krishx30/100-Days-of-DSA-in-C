#include <stdio.h>

#define MAX 100

int main()
{
    int n;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == 0)
            {
                int len = j - i + 1;
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("Length of longest subarray with zero sum:\n");
    printf("%d\n", maxLen);

    return 0;
}