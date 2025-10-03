/*
 * Fibonacci Sequence Verification
 * Calculates the Fibonacci sequence up to the N-th number
 * and verifies the identity F(n+2) = F(n+1) + F(n)
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib_verify.c", 10, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 2);

    long long *fib = malloc(sizeof(long long) * (N + 1));
    if (!fib) {
        abort();
    }

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        // Verify the Fibonacci property for the computed sequence
    }

    // Final verification of the relation F(n+2) = F(n+1) + F(n)
    if (N >= 2) {
        __VERIFIER_assert(fib[N] == fib[N - 1] + fib[N - 2]);
    }

    free(fib);
    return 0;
}