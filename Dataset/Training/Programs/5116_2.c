#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_prog.c", 3, "reach_error"); }
extern void abort(void);
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
    int n, i;
    long long factorial, sum_of_squares;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    factorial = 1;
    sum_of_squares = 0;

    for (i = 1; i <= n; i++) {
        factorial *= i;
        sum_of_squares += i * i;
    }

    // Ensure the program doesn't encounter overflow using assertions
    __VERIFIER_assert(sum_of_squares >= 0);

    printf("Factorial of %d: %lld\n", n, factorial);
    printf("Sum of squares up to %d: %lld\n", n, sum_of_squares);

    return 0;
}