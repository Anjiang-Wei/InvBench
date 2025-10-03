#include <stdio.h>
#include <stdlib.h>

// Helper functions for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "generated_program.c", 10, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// The main function with a loop and meaningful computation
int main(void) {
    int n = 10; // The length of the Fibonacci sequence to compute
    long long fib_prev = 0, fib_curr = 1, fib_next;

    for (int i = 2; i <= n; ++i) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;

        // Here we assert that the current Fibonacci number is positive
    }

    // Assert that after the loop, the 10th Fibonacci number is as expected
    __VERIFIER_assert(fib_curr == 55);

    // Output the last computed Fibonacci number
    printf("The %dth Fibonacci number is: %lld\n", n, fib_curr);

    return 0;
}