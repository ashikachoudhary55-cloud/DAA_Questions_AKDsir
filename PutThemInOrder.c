#include <stdio.h>
#include <math.h>

typedef struct {
    char name[30];
    double value;
} Function;

double f1(double n) {
    return n * log2(n);
}

double f2(double n) {
    return 12 * sqrt(n);
}

double f3(double n) {
    return n / n;
}

double f4(double n) {
    return pow(n, log2(n));
}

double f5(double n) {
    return 100 * n * n + 6 * n;
}

double f6(double n) {
    return pow(n, 0.51);
}

double f7(double n) {
    return n * n - 324;
}

double f8(double n) {
    return 50 * pow(n, 0.5);
}

double f9(double n) {
    return 2 * n * n * n;
}

double f10(double n) {
    return pow(3, n);
}

double f11(double n) {
    return pow(2, 32) * n;
}

double f12(double n) {
    return log2(n);
}

int main() {

    double n = 100000;

    Function a[12] = {
        {"n log2(n)", f1(n)},
        {"12 sqrt(n)", f2(n)},
        {"n/n", f3(n)},
        {"n^(log2 n)", f4(n)},
        {"100n^2 + 6n", f5(n)},
        {"n^0.51", f6(n)},
        {"n^2 - 324", f7(n)},
        {"50n^0.5", f8(n)},
        {"2n^3", f9(n)},
        {"3^n", f10(n)},
        {"2^32 n", f11(n)},
        {"log2(n)", f12(n)}
    };


    for (int i = 0; i < 12; i++) {

        for (int j = i + 1; j < 12; j++) {

            if (a[i].value > a[j].value) {

                Function temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Increasing order of growth:\n\n");

    for (int i = 0; i < 12; i++) {
        printf("%s\n", a[i].name);
    }

    return 0;
}