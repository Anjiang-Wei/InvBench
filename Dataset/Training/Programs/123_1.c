#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "parity_check.c", 6, "reach_error"); }

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
}

int main() {
    int N, i, count_even = 0, count_odd = 0;
    int *numbers;

    // Get a non-deterministic number of entries N
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 1000); // Prevent excessive allocation

    numbers = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(numbers != NULL);

    // Generate non-deterministic numbers and calculate parity counts
    for (i = 0; i < N; i++) {
        numbers[i] = __VERIFIER_nondet_int();
        if (numbers[i] % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    // Check if even + odd = N, which must be true
    __VERIFIER_assert(count_even + count_odd == N);

    // Clean up
    free(numbers);

    return 0;
}