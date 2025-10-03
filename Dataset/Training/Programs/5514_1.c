// The following C program checks a specific numerical property related to Fibonacci numbers.

#include <limits.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib-prop.c", 8, "reach_error"); }
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

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, temp, i;
    for (i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limit n to prevent overflow in fib function

    // Compute Fibonacci number
    int fib_n = fib(n);

    // Validate specific property
    // Here we assert that fib(n) is always less than 2^n
    // Which is a known property of Fibonacci numbers.
    __VERIFIER_assert(fib_n < (1 << n));

    return 0;
}