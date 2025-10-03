#include <stdlib.h>

/* Program structure inspired by previous examples */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 8, "reach_error"); }

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
    int m, n;
    int a = 0, b = 1, i;
    long long sum = 0, factorial = 1;

    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m > 0);
    assume_abort_if_not(m <= 10);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 10);

    // Fibonacci-like operation
    for (i = 0; i < n; i++) {
        int temp = a;
        a = b;
        b = temp + b;
        sum += b;
    }

    // Factorial computation
    for (i = 1; i <= m; i++) {
        factorial *= i;
    }

    // Final assertions to check the validity of computations
    __VERIFIER_assert(factorial > 0 && factorial <= 3628800); // 10! = 3628800

    return 0;
}