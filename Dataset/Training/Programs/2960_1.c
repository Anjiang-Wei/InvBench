/*
 * Benchmark inspired by patterns from Divyesh Unadkat, Supratik Chakraborty, and Ashutosh Gupta.
 * Includes computation and constraint checking suitable for verification tools.
 */

#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 10, "reach_error"); }
extern void abort(void);
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
extern int __VERIFIER_nondet_int(void);
void *malloc(unsigned int size);

int N;

int main() {
    N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int i;
    int *x = malloc(sizeof(int) * N);
    int max_val = 1000000;
    int min_val = -1000000;

    for (i = 0; i < N; i++) {
        x[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(x[i] >= min_val);
        assume_abort_if_not(x[i] <= max_val);
    }

    int max_found = min_val;
    int min_found = max_val;

    for (i = 0; i < N; i++) {
        if (x[i] > max_found) {
            max_found = x[i];
        }

        if (x[i] < min_found) {
            min_found = x[i];
        }
    }

    __VERIFIER_assert(max_found >= min_found);

    return 0;
}