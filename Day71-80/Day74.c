#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    int n;
    char names[MAX][50];
    char unique[MAX][50];
    int count[MAX] = {0};
    int uniqueCount = 0;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter candidate names:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);

        int found = 0;

        for(int j = 0; j < uniqueCount; j++)
        {
            if(strcmp(unique[j], names[i]) == 0)
            {
                count[j]++;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount]++;
            uniqueCount++;
        }
    }

    int maxVotes = -1;
    char winner[50];

    for(int i = 0; i < uniqueCount; i++)
    {
        if(count[i] > maxVotes)
        {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes)
        {
            if(strcmp(unique[i], winner) < 0)
                strcpy(winner, unique[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}