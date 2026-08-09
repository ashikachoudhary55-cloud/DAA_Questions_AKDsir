#include <stdio.h>

long long moves = 0;

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {

    if (n == 0)
        return;

    towerOfHanoi(n - 1,
                 source,
                 destination,
                 auxiliary);

    moves++;

    towerOfHanoi(n - 1,
                 auxiliary,
                 source,
                 destination);
}

int main() {

    FILE *fp = fopen("hanoi_results.csv", "w");

    fprintf(fp, "N,Moves\n");

    printf("N\tMoves\n");

    for (int n = 1; n <= 25; n++) {

        moves = 0;

        towerOfHanoi(n, 'A', 'B', 'C');

        printf("%d\t%lld\n", n, moves);

        fprintf(fp, "%d,%lld\n", n, moves);
    }

    fclose(fp);

    return 0;
}