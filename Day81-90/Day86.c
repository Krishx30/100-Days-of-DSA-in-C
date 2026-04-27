#include <stdio.h>

int main()
{
    long long n;

    printf("Enter number: ");
    scanf("%lld", &n);

    if (n < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    long long left = 0, right = n;
    long long ans = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("Square root:\n");
    printf("%lld\n", ans);

    return 0;
}