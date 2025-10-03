#include <assert.h>

// External functions to be used in verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
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
    int n, sum, i;

    // Get a non-deterministic integer
    n = __VERIFIER_nondet_int();

    // Assume constraints on the input
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    i = 1;

    // Loop to calculate the sum of the first n natural numbers
    while (i <= n) {
        __VERIFIER_assert(sum == (i - 1) * i / 2);
        sum = sum + i;
        i = i + 1;
    }

    // Post-condition: sum should be equal to n*(n+1)/2

    return 0;
}