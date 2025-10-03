#include <stdio.h>
#include <stdlib.h>

// Assume a custom verification function from the environment
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 6, "reach_error"); }
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
    // Variables for the iterative computation
    int n = __VERIFIER_nondet_int();
    int i, sum = 0;

    // Restrict input space to a reasonable range for verification
    assume_abort_if_not(n >= 1 && n <= 1000);

    // Initialize Fibonacci-like sequence
    int a = 0, b = 1, next;

    // Compute Fibonacci-like series and sum of first n terms
    for (i = 1; i <= n; ++i) {
        if (i <= 2) {
            next = i - 1; // First two numbers in Fibonacci-like series: 0, 1
        } else {
            next = a + b; // Next term is the sum of the previous two
            a = b;
            b = next;
        }
        sum += next;
    }

    // Assert that the sum of Fibonacci series is not a negative number
    __VERIFIER_assert(sum >= 0);

    // Print result for validation purpose
    printf("Sum of first %d Fibonacci-like numbers: %d\n", n, sum);

    return 0;
}