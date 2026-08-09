#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int a[MAX];
int n = 0;

int search(int key) {

    int low = 0, high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void insert(int key) {

    int i = n - 1;

    while (i >= 0 && a[i] > key) {
        a[i + 1] = a[i];
        i--;
    }

    a[i + 1] = key;
    n++;
}

void delete(int key) {

    int pos = search(key);

    if (pos == -1)
        return;

    for (int i = pos; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;
}

int minimum() {
    return a[0];
}

int maximum() {
    return a[n - 1];
}

int predecessor(int key) {

    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (a[mid] < key) {
            ans = a[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int successor(int key) {

    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (a[mid] > key) {
            ans = a[mid];
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    FILE *fp = fopen("sorted_array.csv", "w");

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