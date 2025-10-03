/*
 * Program demonstrating conditional logic, array usage, and loops.
 * Designed for analysis and verification by automated tools.
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
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
int __VERIFIER_nondet_int(void);

// Main function
int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int *a = malloc(sizeof(int) * N);
    int *b = malloc(sizeof(int) * N);

    if (!a || !b) {
        return 1; // Memory allocation check
    }

    int i;
    int threshold = __VERIFIER_nondet_int();
    int flag = 0;

    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();
        b[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < N; i++) {
        if (a[i] + b[i] > threshold) {
            flag++;
        } else {
            b[i] = a[i];
        }
    }

    // assert(flag <= N) to verify there are no more than N conditions where a[i] + b[i] > threshold
    __VERIFIER_assert(flag <= N);

    free(a);
    free(b);
    return 0;
}