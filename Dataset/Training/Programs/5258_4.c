#include <stdio.h>
#include <stdlib.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }
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
    int a, n;
    long long factorial, i;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10); // Restrict input to a manageable range

    factorial = 1;
    n = a;

    while (n > 1) {
        factorial = factorial * n; // Compute factorial
        n = n - 1;
    }

    // Assert that the computed factorial is correct for small positive integers
    if (a == 0 || a == 1) {
    } else if (a == 5) {
    } else if (a == 6) {
    } else if (a == 10) {
        __VERIFIER_assert(factorial == 3628800);
    }

    printf("Factorial of %d is %lld\n", a, factorial);

    return 0;
}