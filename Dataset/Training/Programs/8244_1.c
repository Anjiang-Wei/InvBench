/*
  Computing Factorial using Simple Iteration
  This program calculates the factorial of a nondeterministic input.
  It utilizes iterative computation to determine the factorial and
  includes assertions to verify the computation logic at various steps.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, counter = 1;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // limited range to prevent overflow in factorial

    while (counter <= n) {
        factorial = factorial * counter;
        counter++;
    }

    // Assertions to verify basic properties of factorial
    // factorial = n! if n != 0 else factorial = 1 when n = 0
    if (n == 0) {
        __VERIFIER_assert(factorial == 1);
    } else {
    }

    printf("The factorial of %d is %lld.\n", n, factorial);

    return 0;
}