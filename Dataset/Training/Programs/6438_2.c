#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated-program.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    int a = 0, b = 1, sum = 0;
    unsigned int counter = 0;

    // Assume n is a reasonable number for Fibonacci sequence generation
    if (n > 30) {
        return 0; // avoiding too large numbers
    }

    while (counter < n) {
        // Calculate Fibonacci sequence
        int next = a + b;
        a = b;
        b = next;

        // Ensure that Fibonacci numbers are non-negative

        // Sum all numbers in the Fibonacci sequence so far
        sum += a;

        counter++;
    }

    // Check that the sum of the first n Fibonacci numbers is greater than zero for n > 0
    if (n > 0) {
        __VERIFIER_assert(sum > 0);
    }

    printf("Sum of first %u Fibonacci numbers: %d\n", n, sum);
    return 0;
}