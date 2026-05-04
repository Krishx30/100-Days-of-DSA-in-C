#include <stdio.h>

#define MAX 100

void sort(int start[], int end[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (start[i] > start[j])
            {
                int t = start[i];
                start[i] = start[j];
                start[j] = t;

                t = end[i];
                end[i] = end[j];
                end[j] = t;
            }
        }
    }
}

int main()
{
    int n;
    int start[MAX], end[MAX];

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter start times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter end times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &end[i]);

    sort(start, end, n);

    printf("Merged intervals:\n");

    int currStart = start[0];
    int currEnd = end[0];

    for (int i = 1; i < n; i++)
    {
        if (start[i] <= currEnd)
        {
            if (end[i] > currEnd)
                currEnd = end[i];
        }
        else
        {
            printf("%d %d\n", currStart, currEnd);
            currStart = start[i];
            currEnd = end[i];
        }
    }

    printf("%d %d\n", currStart, currEnd);

    return 0;
}