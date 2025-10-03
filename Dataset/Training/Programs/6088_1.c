#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n, m;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 100);
    assume_abort_if_not(m >= 0 && m <= 100);

    int *arrayA = malloc(n * sizeof(int));
    int *arrayB = malloc(m * sizeof(int));

    if (!arrayA || !arrayB) {
        abort();
    }

    for (int i = 0; i < n; i++) {
        arrayA[i] = i + 1;
    }

    for (int j = 0; j < m; j++) {
        arrayB[j] = (j + 1) * 2;
    }

    // Calculate the sum of elements in arrayA and arrayB
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++) {
        sumA += arrayA[i];
    }
    for (int j = 0; j < m; j++) {
        sumB += arrayB[j];
    }

    // Verify that the sum of elements is within a certain range
    assume_abort_if_not(sumA >= 0 && sumA <= 5050);  // Sum of first 100 positive integers
    assume_abort_if_not(sumB >= 0 && sumB <= 10100); // Sum of first 100 multiples of 2

    __VERIFIER_assert(sumA >= 0);

    printf("Sum of arrayA: %d\n", sumA);
    printf("Sum of arrayB: %d\n", sumB);

    free(arrayA);
    free(arrayB);

    return 0;
}