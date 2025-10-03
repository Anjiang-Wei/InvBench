#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int factorial(int n) {
    int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // assume n is between 0 and 10

    int fact = factorial(n);

    // For n between 0 and 10, factorial should always be non-negative

    printf("Factorial of %d is %d\n", n, fact);

    // Check for a specific condition: factorial of 5 should be 120
    if (n == 5) {
        __VERIFIER_assert(fact == 120);
    }

    return 0;
}