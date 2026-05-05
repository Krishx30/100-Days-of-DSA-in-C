#include <stdio.h>
#define MAX 100
void sort(int pos[], float time[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pos[i] < pos[j])
            {
                int tp = pos[i];
                pos[i] = pos[j];
                pos[j] = tp;
                float tt = time[i];
                time[i] = time[j];
                time[j] = tt;
            }
        }
    }
}
int main()
{
    int n, target;
    int pos[MAX], speed[MAX];
    float time[MAX];
    printf("Enter number of cars: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }
    printf("Enter target distance: ");
    scanf("%d", &target);
    printf("Enter positions:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);
    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);
    for (int i = 0; i < n; i++)
    {
        time[i] = (float)(target - pos[i]) / speed[i];
    }
    sort(pos, time, n);
    int fleets = 0;
    float curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (time[i] > curr)
        {
            fleets++;
            curr = time[i];
        }
    }
    printf("Number of car fleets:\n");
    printf("%d\n", fleets);
    return 0;
}