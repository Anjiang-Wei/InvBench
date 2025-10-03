#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int __VERIFIER_nondet_int(void);

void reach_error() {
    __assert_fail("0", "sample.c", 6, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
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

int main() {
    int n, x, sum;

    n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 1000) {
        return 0; // Avoid very large or invalid n for practical purposes
    }

    x = 0;
    sum = 0;

    while (x < n) {
        int delta = __VERIFIER_nondet_int();
        assume_abort_if_not(delta > 0); // delta must be positive
        if (delta > 10) {
            delta = 10; // cap delta to a maximum of 10 to prevent overflow
        }

        sum += delta;
        if (sum >= n) {
            break; // break when sum is >= n
        }

        x++;
    }

    // Verify final conditions
    __VERIFIER_assert(x <= n);

    // Output for manual inspection
    printf("n: %d, final sum: %d, iterations: %d\n", n, sum, x);

    return 0;
}