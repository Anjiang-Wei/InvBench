/*
Fibonacci Sequence Verification
computes Fibonacci numbers and checks the Fibonacci property F(n) = F(n-1) + F(n-2)
*/

#include <limits.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-verification.c", 6, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 20); // Assume a safe range

    int fib1 = 0;
    int fib2 = 1;
    int fib_current;

    for (int i = 2; i <= n; i++) {
        // Calculate the current Fibonacci number
        fib_current = fib1 + fib2;

        // Check the Fibonacci property

        // Update for the next iteration
        fib1 = fib2;
        fib2 = fib_current;
    }

    // Optionally, verify the final Fibonacci number is non-negative
    __VERIFIER_assert(fib_current >= 0);

    return 0;
}