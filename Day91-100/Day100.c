#include <stdio.h>
#define MAX 100
struct Node
{
    int value;
    int index;
};
void merge(struct Node arr[], struct Node temp[], int left, int mid, int right, int count[])
{
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right)
    {
        if(arr[i].value <= arr[j].value)
        {
            count[arr[i].index] += (j - (mid + 1));
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid)
    {
        count[arr[i].index] += (j - (mid + 1));
        temp[k++] = arr[i++];
    }
    while(j <= right)
        temp[k++] = arr[j++];
    for(int i = left; i <= right; i++)
        arr[i] = temp[i];
}
void mergeSort(struct Node arr[], struct Node temp[], int left, int right, int count[])
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid + 1, right, count);
        merge(arr, temp, left, mid, right, count);
    }
}
int main()
{
    int n;
    int arr[MAX];
    struct Node nodes[MAX], temp[MAX];
    int count[MAX];
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
        nodes[i].value = arr[i];
        nodes[i].index = i;
        count[i] = 0;
    }
    mergeSort(nodes, temp, 0, n - 1, count);
    printf("Count of smaller elements on right:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", count[i]);
    }
    printf("\n");
    return 0;
}