/*
 * New Example Program - Verification of Arithmetic Progression Properties
 * This program demonstrates the verification of properties in an arithmetic progression.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }

    assume_abort_if_not(N < 10000); // Assuming a reasonable upper limit for computational complexity

    long long *sequence = malloc(sizeof(long long) * N);
    if (sequence == NULL) {
        return 1;
    }

    sequence[0] = 2; // Start of the arithmetic progression
    long long sum = 0;
    long long expected_sum = 0;
    int i;

    for (i = 0; i < N; i++) {
        if (i > 0) {
            sequence[i] = sequence[i - 1] + 5;
        }
        sum += sequence[i];
        expected_sum += 2 + i * 5;
    }

    __VERIFIER_assert(sum == expected_sum);

    // Clean up
    free(sequence);

    return 0;
}