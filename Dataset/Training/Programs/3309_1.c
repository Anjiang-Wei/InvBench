#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_condition.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int m, n;
    long long fib_prev, fib_curr, fib_next;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    fib_prev = 0;
    fib_curr = 1;

    int i;
    for (i = 1; i <= m; ++i) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    long long factorial = 1;
    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Ensure fib_curr and factorial are not overflowing by asserting an arbitrary condition tied to the problem's constraints.
    __VERIFIER_assert(fib_curr >= 0 && factorial >= 0);

    // Assuming some post-condition
    if (m == n) {
    }

    printf("Fibonacci of %d is %lld\n", m, fib_curr);
    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}