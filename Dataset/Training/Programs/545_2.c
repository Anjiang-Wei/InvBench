// divisor_search.c
// A C program that finds the smallest non‐trivial divisor of a nondeterministic integer n
// and checks postconditions via __VERIFIER_assert.

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "divisor_search.c", 7, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    // Pick an integer n in [2, 1e6]
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 1000000);

    // d will hold the smallest divisor > 1, or remain 0 if n is prime
    int d = 0;
    int i = 2;

    // Search for a divisor by trial up to sqrt(n)
    while (i * i <= n && d == 0) {
        if (n % i == 0) {
            d = i; // found the smallest divisor
        }
        i++;
    }

    if (d > 0) {
        // Composite case: n == d * k with d,k >= 2
        int k = n / d;
        __VERIFIER_assert(d * k == n);
    } else {
        // Prime case: no divisor found in [2..sqrt(n)]
    }

    return 0;
}