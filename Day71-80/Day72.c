#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int freq[26] = {0};

    printf("Enter string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        int index = str[i] - 'a';

        if(freq[index] == 1)
        {
            printf("%c\n", str[i]);
            return 0;
        }

        freq[index]++;
    }

    printf("-1\n");

    return 0;
}