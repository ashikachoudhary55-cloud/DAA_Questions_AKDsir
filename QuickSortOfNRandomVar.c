#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void quicksort(int a[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
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
    quicksort(a, 0, n - 1);
    f = fopen("output.txt", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(f, "%d ", a[i]);
        printf("%d ", a[i]);
    }
    fclose(f);
    return 0;
}
