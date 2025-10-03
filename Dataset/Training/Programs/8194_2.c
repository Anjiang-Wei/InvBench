#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }
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
    int n;
    long long factorial = 1;
    long long double_factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // ensuring n is within a reasonable range

    int i = 1;

    while (i <= n) {
        factorial *= i;
        i++;
    }

    int j = 2;

    while (j <= n) {
        double_factorial *= j;
        j += 2;
    }

    // We can assert some known properties of factorials and double factorials for analysis
    __VERIFIER_assert(double_factorial >= 1);

    printf("Factorial of %d is %lld\n", n, factorial);
    printf("Double factorial of %d is %lld\n", n, double_factorial);

    return 0;
}