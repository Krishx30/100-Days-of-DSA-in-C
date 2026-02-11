#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int left, right;
    int isPalindrome = 1;

    printf("Enter string: ");
    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES, IT IS A PALINDROME");
    else
        printf("NO, IT IS NOT A PALINDROME");

    return 0;
}
