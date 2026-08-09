#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int key) {

    Node *newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = NULL;

    return newNode;
}

Node* search(int key) {

    Node *temp = head;

    while (temp != NULL) {

        if (temp->key == key)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void insert(int key) {

    Node *newNode = createNode(key);

    newNode->next = head;
    head = newNode;
}

void delete(int key) {

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->key != key) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

int minimum() {

    Node *temp = head;

    int mn = temp->key;

    temp = temp->next;

    while (temp != NULL) {

        if (temp->key < mn)
            mn = temp->key;

        temp = temp->next;
    }

    return mn;
}

int maximum() {

    Node *temp = head;

    int mx = temp->key;

    temp = temp->next;

    while (temp != NULL) {

        if (temp->key > mx)
            mx = temp->key;

        temp = temp->next;
    }

    return mx;
}

int predecessor(int key) {

    Node *temp = head;

    int ans = -1;

    while (temp != NULL) {

        if (temp->key < key) {

            if (ans == -1 || temp->key > ans)
                ans = temp->key;
        }

        temp = temp->next;
    }

    return ans;
}

int successor(int key) {

    Node *temp = head;

    int ans = -1;

    while (temp != NULL) {

        if (temp->key > key) {

            if (ans == -1 || temp->key < ans)
                ans = temp->key;
        }

        temp = temp->next;
    }

    return ans;
}

int main() {

    FILE *fp = fopen("unsorted_singly.csv", "w");

    fprintf(fp, "n,Search,Insert,Delete,Min,Max,Predecessor,Successor\n");

    int sizes[] = {1000, 5000, 10000, 20000, 50000, 100000};

    for (int x = 0; x < 6; x++) {

        head = NULL;

        int n = sizes[x];

        for (int i = 1; i <= n; i++)
            insert(i);

        int key = n / 2;

        clock_t start, end;

        start = clock();
        search(key);
        end = clock();
        double t1 = (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        insert(n+1);
        end = clock();
        double t2 = (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        delete(key);
        end = clock();
        double t3 = (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        minimum();
        end = clock();
        double t4 = (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        maximum();
        end = clock();
        double t5 = (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        predecessor(key);
        end = clock();
        double t6 = (double)(end-start)/CLOCKS_PER_SEC;

        start = clock();
        successor(key);
        end = clock();
        double t7 = (double)(end-start)/CLOCKS_PER_SEC;

        fprintf(fp, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                n,t1,t2,t3,t4,t5,t6,t7);
    }

    fclose(fp);

    return 0;
}