#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int a, b, n, sum_even, sum_odd;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    sum_even = 0;
    sum_odd = 0;
    a = 0;
    b = 1;

    for (int i = 0; i < n; ++i) {
        int next = a + b;
        if (next % 2 == 0) {
            sum_even += next;
        } else {
            sum_odd += next;
        }

        a = b;
        b = next;

        // Check a constraint related to the Fibonacci sequence properties
        // Verify whether at any time sum of even Fibonacci numbers minus sum of odd ones is not greater than n
    }

    // Additional valid post-condition for the computed sums
    __VERIFIER_assert(sum_even >= 0 && sum_odd >= 0);

    return 0;
}