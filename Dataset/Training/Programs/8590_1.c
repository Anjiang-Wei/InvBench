#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "my_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b;

    assume_abort_if_not(a >= 0 && a <= 10); // Limit the range for practical solvability

    // Computational logic using factorial
    if (a % 2 == 0) {
        b = factorial(a);
    } else {
        b = factorial(a - 1);
    }

    // Constraint checking: ensure factorial is within a valid range
    __VERIFIER_assert(b >= 1 && b <= 3628800); // 3628800 is 10!

    printf("Input: %d, Result: %d\n", a, b);
    return 0;
}