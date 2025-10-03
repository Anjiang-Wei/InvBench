#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error(void) {
    printf("ERROR\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

#define MAX_VALUE 1000

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < MAX_VALUE);

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        // Failed to allocate memory
        return 1;
    }

    int i;
    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int(); // Initialize array with some values
    }

    long long sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    long long product = 1;
    for (i = 0; i < n; i++) {
        product *= (arr[i] == 0) ? 1 : arr[i]; // Ignore zero to prevent product from becoming zero
    }

    // A speculative constraint: if sum is even, the product should not be zero
    if (sum % 2 == 0) {
        __VERIFIER_assert(product != 0);
    }

    free(arr);
    return 0;
}