#include <stdio.h>
#include <stdlib.h>

// A program to calculate Fibonacci numbers and verify properties
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", __LINE__, "reach_error"); }
extern int __VERIFIER_nondet_int();
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
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(void) {
    int num = __VERIFIER_nondet_int();
    if (num < 0) {
        return 0; // To ensure validity of Fibonacci calculation
    }

    int fib = fibonacci(num);
    printf("Fibonacci(%d) = %d\n", num, fib);

    // Property: For n ≥ 1, Fibonacci(n) should be greater than or equal to n-1
    // Let's verify this.
    if (num >= 1) {
        __VERIFIER_assert(fib >= num - 1);
    }

    return 0;
}