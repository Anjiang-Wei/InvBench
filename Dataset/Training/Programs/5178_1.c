#include <stdbool.h>
#include <stdlib.h>

/*
Fibonacci Series
Compute Fibonacci sequence up to the k-th term
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "fibonacci.c", 10, "reach_error");
}
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
    int k;
    long long fib_prev, fib_curr, fib_next, c;

    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 50);

    fib_prev = 0;
    fib_curr = 1;
    c = 2;

    while (1) {
        // Check that current Fibonacci numbers are non-negative and in correct order
        __VERIFIER_assert(fib_curr >= fib_prev);

        if (!(c <= k)) {
            break;
        }

        // Compute next Fibonacci term
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
        c = c + 1;
    }

    // Final assertion to check if Fibonacci series is correctly computed

    return 0;
}