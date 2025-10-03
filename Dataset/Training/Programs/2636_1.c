#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
    int n, i;
    int sum = 0;
    int product = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Assume n is within a reasonable range

    i = 1;
    while (i <= n) {
        sum += i;
        product *= i;
        i++;
    }

    printf("Sum of first %d natural numbers: %d\n", n, sum);
    printf("Product of first %d natural numbers: %d\n", n, product);

    // A non-trivial assertion based on mathematical formula
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    return 0;
}