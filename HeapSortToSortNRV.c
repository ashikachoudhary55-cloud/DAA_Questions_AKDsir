#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int a[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;
    if (l < n && a[l] > a[m])
        m = l;
    if (r < n && a[r] > a[m])
        m = r;
    if (m != i)
    {
        swap(&a[i], &a[m]);
        heapify(a, n, m);
    }
}
void heapsort(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
int main()
{
    int a[100], n, i;
    FILE *f;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    srand(time(0));
    f = fopen("input.txt", "w");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        fprintf(f, "%d ", a[i]);
    }
    fclose(f);
    f = fopen("input.txt", "r");
    for (i = 0; i < n; i++)
        fscanf(f, "%d", &a[i]);
    fclose(f);
    heapsort(a, n);
    f = fopen("output.txt", "w");
    printf("Sorted elements:\n");
    for (i = 0; i < n; i++)
    {
        fprintf(f, "%d ", a[i]);
        printf("%d ", a[i]);
    }
    fclose(f);
    return 0;
}
