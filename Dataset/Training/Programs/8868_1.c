/*
Arithmetic Series
computes the sum of arithmetic series: s = n * (2 * a + (n - 1) * d) / 2
where s is the sum, n is the number of terms, a is the first term, and d is the common difference
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "arith-series.c", 9, "reach_error"); }

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

int main() {
    unsigned int n, a, d;
    long long s, term, i;

    n = 20; // You can use a nondeterministic function or random value
    a = 5;  // Initial term
    d = 2;  // Common difference

    s = 0;
    term = a;
    i = 0;

    while (i < n) {
        s += term; // Add the current term to the sum
        term += d; // Go to the next term in the arithmetic sequence
        i++;
    }

    // Check if the computed sum is correct
    // Sum of an arithmetic series: s = n * (2*a + (n-1)*d) / 2
    __VERIFIER_assert(s == n * (2 * a + (n - 1) * d) / 2);

    printf("Computed sum: %lld\n", s);
    return 0;
}