#include <stdio.h>

int main()
{
    int p, q, i, j, k;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    int a[p];

    printf("Enter sorted arrival times of server log 1:\n");
    for(i = 0; i < p; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    int b[q];

    printf("Enter sorted arrival times of server log 2:\n");
    for(i = 0; i < q; i++)
    {
        scanf("%d", &b[i]);
    }

    int c[p + q];

    i = 0;
    j = 0;
    k = 0;

    while(i < p && j < q)
    {
        if(a[i] <= b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < p)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < q)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged chronological log:\n");
    for(i = 0; i < p + q; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
