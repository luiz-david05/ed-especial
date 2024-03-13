#include <stdio.h>

void incrementa_vetor (int n, int* v);

int main () {
    int v[] = {1, 3, 5};
    incrementa_vetor(3, v);

    int i = 0;
    for (; i < 3; i++) {
        printf("elemento [%d] = %d\n", i, v[i]);
    }

    return 0;
}

void incrementa_vetor(int n, int* v) {
    int i = 0;
    for (; i < n; i++) {
        v[i] += 2;
    }
}