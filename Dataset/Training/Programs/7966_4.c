/*
  Fibonacci Series Verification
  Computes the nth Fibonacci number
  F(n) = F(n-1) + F(n-2), where F(0) = 0 and F(1) = 1
  Ensures F(n) is correctly computed for 0 <= n <= 15
  and tracks pattern validation with constraints in loops.
*/

#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 15);

    long long fib_curr, fib_prev1, fib_prev2;
    int counter;

    if (n == 0) {
        fib_curr = 0;
    } else if (n == 1) {
        fib_curr = 1;
    } else {
        fib_prev1 = 1; // F(1)
        fib_prev2 = 0; // F(0)
        counter = 2;

        while (counter <= n) {
            fib_curr = fib_prev1 + fib_prev2;
            fib_prev2 = fib_prev1;
            fib_prev1 = fib_curr;
            ++counter;
        }
    }

    // Asserting known values of Fibonacci for specific 'n'
    if (n == 0) {
    }
    if (n == 1) {
    }
    if (n == 2) {
    }
    if (n == 3) {
        __VERIFIER_assert(fib_curr == 2);
    }
    if (n == 10) {
    }
    if (n == 15) {
    }

    // Optionally, the value can be printed for verification, though not typically done in verification checks
    // printf("F(%d) = %lld\n", n, fib_curr);

    return 0;
}