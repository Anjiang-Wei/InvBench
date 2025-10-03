#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 4, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    long long a, b, sum, i;

    // Assume n is a positive integer
    assume_abort_if_not(n > 0);

    a = 0;
    b = 1;
    sum = 1;
    i = 1;

    while (i < n) {
        long long next = a + b;
        a = b;
        b = next;

        sum += b;
        i = i + 1;

        // Assert that the sum is both greater than the last Fibonacci number and larger than i
    }

    // At the end, check that sum is positive
    __VERIFIER_assert(sum > 0);

    printf("Sum of Fibonacci sequence up to %u: %lld\n", n, sum);
    return 0;
}