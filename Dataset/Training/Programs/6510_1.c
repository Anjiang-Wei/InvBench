/*
 * Fibonacci Series Sum Verification
 *
 * This program calculates the sum of a Fibonacci series up to the N-th term,
 * and verifies that the sum is equal to F(N+2) - 1, where F(N) is the N-th
 * Fibonacci number. The initial assumptions ensure a reasonable range for N.
 */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 30); // Restrict N to a reasonable range

    int fib_prev = 0;
    int fib_curr = 1;
    int fib_next;
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        sum += fib_curr;
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    // Now fib_curr is F(N+1), and fib_prev is F(N)
    fib_next = fib_prev + fib_curr; // fib_next now holds F(N+2)

    // Verify that the sum of the first N Fibonacci numbers is F(N+2) - 1
    __VERIFIER_assert(sum == fib_next - 1);

    return 0;
}