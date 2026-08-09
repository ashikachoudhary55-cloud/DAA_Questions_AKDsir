#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    long long tosses[] = {
        1000,
        10000,
        100000,
        1000000,
        10000000
    };

    int count = 5;

    double probability[] = {0.5, 0.7};

    srand(time(NULL));

    FILE *fp = fopen("coin_results.csv", "w");

    fprintf(fp, "Tosses,Fair,Biased\n");

    for (int i = 0; i < count; i++) {

        long long n = tosses[i];

        long long fairHeads = 0;
        long long biasedHeads = 0;

        for (long long j = 0; j < n; j++) {

            double r = (double)rand() / RAND_MAX;

            if (r < probability[0])
                fairHeads++;

            r = (double)rand() / RAND_MAX;

            if (r < probability[1])
                biasedHeads++;
        }

        double fairProb =
            (double)fairHeads / n;

        double biasedProb =
            (double)biasedHeads / n;

        printf("Tosses = %lld\n", n);
        printf("Fair coin   = %lf\n", fairProb);
        printf("Biased coin = %lf\n\n", biasedProb);

        fprintf(fp, "%lld,%lf,%lf\n",
                n, fairProb, biasedProb);
    }

    fclose(fp);

    return 0;
}
