#include <stdio.h>
#include <stdlib.h>

int findPartition(int a[], int n) {

    int low = 0;
    int high = n - 1;

    int answer = n;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (a[mid] == 1) {

            answer = mid;
            high = mid - 1;
        }
        else {

            low = mid + 1;
        }
    }

    return answer;
}

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter array containing 0s followed by 1s:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int position = findPartition(a, n);

    if (position == n)
        printf("No 1 exists in the array.\n");

    else
        printf("Partition point = %d\n", position);

    free(a);

    return 0;
}