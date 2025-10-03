#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
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

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 20);

    // The task here will compute the sum of Fibonacci sequence up to n
    int fib_sum = 0;
    int i;
    for (i = 0; i <= n; ++i) {
        fib_sum += fibonacci(i);
    }

    // Verify implementation by comparing the sum for small numbers
    if (n == 0) {
    }
    if (n == 1) {
        __VERIFIER_assert(fib_sum == 1);
    }
    if (n == 2) {
    }
    if (n == 3) {
    }
    if (n == 4) {
    }

    return 0;
}