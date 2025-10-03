/* A C program that performs Fibonacci sequence computation with a constraint */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-constraint.c", 5, "reach_error"); }
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
    int n;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 46); // to prevent integer overflow

    int a = 0, b = 1, c, i;

    if (n == 0) {
        c = 0;
    } else if (n == 1) {
        c = 1;
    } else {
        for (i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
    }

    // Constraint: The Fibonacci number must not exceed 1836311903 for inputs between 0 and 46.
    __VERIFIER_assert(c <= 1836311903);

    printf("Fibonacci number for %d is %d\n", n, c);
    return 0;
}