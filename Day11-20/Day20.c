#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    int freq[20001] = {0}; // For simplicity (adjust if needed)
    int offset = 10000;    // To handle negative sums

    freq[offset] = 1; // Prefix sum 0 initially

    for (i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (freq[prefixSum + offset] > 0)
        {
            count += freq[prefixSum + offset];
        }

        freq[prefixSum + offset]++;
    }

    printf("Count of subarrays with sum zero: %d", count);

    return 0;
}