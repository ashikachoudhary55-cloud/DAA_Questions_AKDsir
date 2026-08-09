#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int a[MAX];
int n = 0;

int search(int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key)
            return i;
    }
    return -1;
}

void insert(int key) {
    a[n] = key;
    n++;
}

void delete(int key) {
    int pos = search(key);

    if (pos == -1)
        return;

    a[pos] = a[n - 1];
    n--;
}

int minimum() {
    int mn = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < mn)
            mn = a[i];
    }

    return mn;
}

int maximum() {
    int mx = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > mx)
            mx = a[i];
    }

    return mx;
}

int predecessor(int key) {
    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] < key) {
            if (ans == -1 || a[i] > ans)
                ans = a[i];
        }
    }

    return ans;
}

int successor(int key) {
    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > key) {
            if (ans == -1 || a[i] < ans)
                ans = a[i];
        }
    }

    return ans;
}

int main() {

    FILE *fp = fopen("unsorted_array.csv", "w");

    fprintf(fp, "n,Search,Insert,Delete,Min,Max,Predecessor,Successor\n");

    int sizes[] = {1000, 5000, 10000, 20000, 50000, 100000};

    for (int x = 0; x < 6; x++) {

        n = 0;

        int size = sizes[x];

        for (int i = 1; i <= size; i++)
            insert(i);

        int key = size / 2;

        clock_t start, end;

        start = clock();
        search(key);
        end = clock();
        double t1 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        insert(size + 1);
        end = clock();
        double t2 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        delete(key);
        end = clock();
        double t3 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        minimum();
        end = clock();
        double t4 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        maximum();
        end = clock();
        double t5 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        predecessor(key);
        end = clock();
        double t6 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        successor(key);
        end = clock();
        double t7 = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(fp, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                size, t1, t2, t3, t4, t5, t6, t7);
    }

    fclose(fp);

    return 0;
}