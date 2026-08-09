#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int unique(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (a[i] == a[j])
                return 0;
        }
    }

    return 1;
}

int main() {

    int sizes[] = {
        100, 200, 500,
        1000, 2000, 5000
    };

    int count = 6;

    FILE *fp = fopen("uniqueness_results.csv", "w");

    fprintf(fp, "N,Comparisons\n");

    srand(10);

    for (int x = 0; x < count; x++) {

        int n = sizes[x];

        int *a =
            malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            a[i] = rand();

        long long comparisons = 0;

        /* Count comparisons */

        for (int i = 0; i < n - 1; i++) {

            for (int j = i + 1; j < n; j++) {

                comparisons++;

                if (a[i] == a[j])
                    break;
            }
        }

        int result = unique(a, n);

        printf("n = %d\n", n);

        if (result)
            printf("All elements are unique.\n");
        else
            printf("Duplicate elements exist.\n");

        printf("Comparisons = %lld\n\n",
               comparisons);

        fprintf(fp, "%d,%lld\n",
                n, comparisons);

        free(a);
    }

    fclose(fp);

    return 0;
}