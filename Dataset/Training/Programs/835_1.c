#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 5, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

unsigned long factorial(unsigned int n) {
    unsigned long result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    unsigned int n;
    unsigned long fact = 1;

    // Assume a non-deterministic value for verification
    n = 5; // You can replace this with a nondeterministic input in a verification tool

    assume_abort_if_not(n <= 12); // Prevent overflow for unsigned long in typical systems

    unsigned int i = 1;
    while (i <= n) {
        fact *= i;
        i++;
    }

    unsigned long expected_fact = factorial(n);

    __VERIFIER_assert(fact == expected_fact);

    printf("Factorial of %u is %lu\n", n, fact);
    return 0;
}