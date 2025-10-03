/*
Fibonacci Series Verification
Computes Fibonacci numbers and verifies the last computed number with a pre-calculated value.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 10, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int n;
    n = __VERIFIER_nondet_int();

    // Constraints on the input
    assume_abort_if_not(n >= 0 && n <= 30);

    // Base values
    int fib_prev = 0; // F(0)
    int fib_curr = 1; // F(1)
    int fib_next;
    int count = 1; // Start from the second Fibonacci number

    if (n == 0) {
    } else if (n == 1) {
    } else {
        while (count < n) {
            fib_next = fib_prev + fib_curr; // F(n) = F(n-1) + F(n-2)
            fib_prev = fib_curr;
            fib_curr = fib_next;
            count++;
        }

        // Pre-calculated Fibonacci value for verification
        if (n == 30) {
            __VERIFIER_assert(fib_curr == 832040); // F(30) = 832040
        }
    }

    // Output the final computed Fibonacci number
    printf("Fibonacci(%d) = %d\n", n, fib_curr);

    return 0;
}