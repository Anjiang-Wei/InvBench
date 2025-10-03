#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

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

int fibonacci_iterative(int n) {
    int a = 0, b = 1, next;
    for (int i = 1; i < n; ++i) {
        next = a + b;
        a = b;
        b = next;
    }
    return a;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int result;

    assume_abort_if_not(n >= 0 && n <= 30);

    result = fibonacci_iterative(n);

    // Check property: Fibonacci series
    if (n > 1) {
    } else {
        __VERIFIER_assert(result == 0 || result == 1);
    }

    printf("Fibonacci(%d) = %d\n", n, result);

    return 0;
}