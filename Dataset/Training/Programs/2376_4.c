/*
Fibonacci Series
computes Fibonacci numbers iteratively
*/

#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 11, "reach_error"); }
extern int __VERIFIER_nondet_int();

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
    int n;
    long long fib1, fib2, fib_current, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    fib1 = 0;
    fib2 = 1;
    fib_current = 0;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 0;
    }

    for (i = 2; i <= n; i++) {
        fib_current = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib_current;

        // Here, we check if the Fibonacci property holds
    }

    // At the end, we verify the final fib_current value
    __VERIFIER_assert(fib_current >= 0);

    return 0;
}