#include <stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[], int l, int r)
{
    int p = a[r], i = l, j;
    for (j = l; j < r; j++)
    {
        if (a[j] <= p)
            swap(&a[i++], &a[j]);
    }
    swap(&a[i], &a[r]);
    return i;
}
int quickselect(int a[], int l, int r, int k)
{
    int p;
    if (l == r)
        return a[l];
    p = partition(a, l, r);
    if (p == k)
        return a[p];
    if (k < p)
        return quickselect(a, l, p - 1, k);
    return quickselect(a, p + 1, r, k);
}
int main()
{
    int a[100], n, k, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter K: ");
    scanf("%d", &k);
    if (k < 1 || k > n)
    {
        printf("Invalid K");
        return 0;
    }
    printf("%dth smallest element = %d",
           k, quickselect(a, 0, n - 1, k - 1));


    return 0;
}
