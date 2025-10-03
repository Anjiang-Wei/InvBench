#include <stdio.h>
#include <stdlib.h>

// Example C program designed to be analyzable and verifiable
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 5, "reach_error"); }
extern void abort(void);
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

extern int __VERIFIER_nondet_int(void);

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume reasonable bounds for verification
    assume_abort_if_not(n >= 0 && n <= 20);

    int sum = 0;
    int i = 0;

    while (i++ < n) {
        // Calculate Fibonacci number and accumulate it to sum
        int fn = fib(i);
        sum += fn;
    }

    // Ensure sum is non-negative; basic sanity check
    __VERIFIER_assert(sum >= 0);

    printf("Sum of first %d Fibonacci numbers is: %d\n", n, sum);
    return 0;
}