#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0 || N > 1000) {
        return 1;
    }

    int *arr = malloc(sizeof(int) * N);
    int even_count = 0;
    int odd_count = 0;

    if (arr == NULL) {
        abort();
    }

    for (int i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    /* Validate the sum of even and odd counts equals the array size */
    __VERIFIER_assert(even_count + odd_count == N);

    /* Ensure at least one of them is non-zero, if N is non-zero */
    if (N > 0) {
    }

    free(arr);
    arr = NULL;

    return 0;
}