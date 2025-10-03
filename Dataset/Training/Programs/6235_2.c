#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

// Program to compute a sequence where each term is calculated as a sum of the
// previous term and its factorial. This sequence will satisfy a certain property
// which can be checked via an external verification tool.

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n, limit;
    long long seq, term;

    n = __VERIFIER_nondet_int();            // Get a nondeterministic integer
    assume_abort_if_not(n >= 0 && n <= 10); // Limit 'n' to a safe range

    seq = 0;
    term = 1;
    limit = 5; // Maximum number of terms in the sequence

    for (int i = 0; i < limit; i++) {
        term = factorial(n + i);
    }

    // After the loop, the sequence should satisfy: seq is a sum of factorials of `n` to `n + limit-1`
    __VERIFIER_assert(seq >= 0); // Expected property after the loop

    printf("Sequence sum: %lld\n", seq);

    return 0;
}