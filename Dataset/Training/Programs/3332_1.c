#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
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
    int n, factorial = 1, i;

    n = __VERIFIER_nondet_int();            // Nondeterministic input
    assume_abort_if_not(n >= 0 && n <= 12); // Assume n within range for factorials

    for (i = 1; i <= n; i++) {
        factorial *= i;
    }

    if (n == 5) {
        __VERIFIER_assert(factorial == 120); // Known value of 5!
    } else if (n == 0) {
        __VERIFIER_assert(factorial == 1); // Known value of 0!
    }

    printf("Factorial of %d is %d\n", n, factorial);
    return 0;
}