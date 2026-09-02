
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 50
void add(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}
void multiply(int a[MAX][MAX], int b[MAX][MAX],
              int c[MAX][MAX], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}
int zeroMatrix(int a[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != 0)
                return 0;
    return 1;
}
int symmetric(int a[MAX][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[i][j] != a[j][i])
                return 0;
    return 1;
}
double determinant(int a[MAX][MAX], int n)
{
    double b[MAX][MAX], det = 1;
    int i, j, k;
    double factor;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            b[i][j] = a[i][j];
    for (i = 0; i < n; i++)
    {
        if (b[i][i] == 0)
            return 0;
        for (j = i + 1; j < n; j++)
        {
            factor = b[j][i] / b[i][i];
            for (k = i; k < n; k++)
                b[j][k] -= factor * b[i][k];
        }
        det *= b[i][i];
    }
    return det;
}
void transpose(int a[MAX][MAX], int n)
{
    int i, j, t;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
}
int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int n, i, j;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    add(a, b, c, n);
    multiply(a, b, c, n);
    printf("Zero Matrix: %s\n",
           zeroMatrix(a, n) ? "Yes" : "No");
    printf("Symmetric Matrix: %s\n",
           symmetric(a, n) ? "Yes" : "No");
    printf("Determinant = %.2f\n", determinant(a, n));
    transpose(a, n);
    printf("Transpose completed in-place.\n");
    printf("Eigenvalue/Eigenvector: O(n^3) using QR method.\n");
    return 0;
}
