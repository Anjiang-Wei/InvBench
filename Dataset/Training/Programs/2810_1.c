#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int fibonacci(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0) {
        return a;
    }
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int x = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0);
    assume_abort_if_not(x <= 20); // Limit x to avoid overflow in Fibonacci

    int fib = fibonacci(x);

    // Verification: The Fibonacci number sequence should not contain negative numbers
    __VERIFIER_assert(fib >= 0);

    // Additional loop
    int accumulator = 0;
    for (int i = 0; i <= 5; i++) {
        accumulator += i;
    }

    // Verification: After the loop, accumulator should be the sum of numbers 0 to 5.

    return 0;
}