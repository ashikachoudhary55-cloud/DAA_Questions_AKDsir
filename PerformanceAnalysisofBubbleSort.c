#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long bubble1(int a[], int n) {

    long long comparisons = 0;

    for (int i = 0; i < n - 1; i++) {

        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {

            comparisons++;

            if (a[j] > a[j + 1]) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }

    return comparisons;
}



long long bubble2(int a[], int n) {

    long long comparisons = 0;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            comparisons++;

            if (a[j] > a[j + 1]) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return comparisons;
}


int main() {

    int sizes[] = {
        100, 200, 500, 1000, 2000, 5000
    };

    int count = 6;

    FILE *fp = fopen("bubble_results.csv", "w");

    fprintf(fp,
            "N,OptimizedBubble,NormalBubble\n");

    srand(10);

    for (int x = 0; x < count; x++) {

        int n = sizes[x];

        int *a = malloc(n * sizeof(int));
        int *b = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {

            a[i] = rand();
            b[i] = a[i];
        }

        long long c1 = bubble1(a, n);
        long long c2 = bubble2(b, n);

        printf("n = %d\n", n);
        printf("Optimized Bubble = %lld\n", c1);
        printf("Normal Bubble    = %lld\n\n", c2);

        fprintf(fp, "%d,%lld,%lld\n",
                n, c1, c2);

        free(a);
        free(b);
    }

    fclose(fp);

    return 0;
}