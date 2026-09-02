#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void maximum(int a[], int n)
{
    int i, max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
}
void largest2(int a[], int n)
{
    int i, x = -999999, y = -999999;
    for (i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            y = x;
            x = a[i];
        }
        else if (a[i] > y && a[i] != x)
            y = a[i];
    }
}
double mean(int a[], int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}
void median(int a[], int n)
{
    int i, j, t;
    double med;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    if (n % 2)
        med = a[n / 2];
    else
        med = (a[n / 2 - 1] + a[n / 2]) / 2.0;
}
double standardDeviation(int a[], int n)
{
    int i;
    double m = mean(a, n), sum = 0;
    for (i = 0; i < n; i++)
        sum += (a[i] - m) * (a[i] - m);
    return sqrt(sum / n);
}
void mode(int a[], int n)
{
    int i, j, count, max = 0;
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
            if (a[i] == a[j])
                count++;
        if (count > max)
            max = count;
    }
}
void removeDuplicates(int a[], int *n)
{
    int i, j, k;
    for (i = 0; i < *n; i++)
    {
        for (j = i + 1; j < *n; j++)
        {
            if (a[i] == a[j])
            {
                for (k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];
                (*n)--;
                j--;
            }
        }
    }
}
void reverse(int a[], int n)
{
    int i, t;
    for (i = 0; i < n / 2; i++)
    {
        t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
}
void partition(int a[], int n, int pivot)
{
    int i, j = 0, t;
    for (i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            j++;
        }
    }
}
int main()
{
    int n, i;
    int a[10000];
    printf("Enter n: ");
    scanf("%d", &n);
    srand(time(0));
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;
    maximum(a, n);
    largest2(a, n);
    mean(a, n);
    median(a, n);
    standardDeviation(a, n);
    mode(a, n);
    removeDuplicates(a, &n);
    reverse(a, n);
    partition(a, n, 50);
    printf("All operations performed successfully.\n");
    return 0;
}
