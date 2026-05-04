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

    printf("Enter number of meetings: ");
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

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (start[i] < end[j])
        {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    printf("Minimum rooms required:\n");
    printf("%d\n", maxRooms);

    return 0;
}