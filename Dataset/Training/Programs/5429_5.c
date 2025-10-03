#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() { assert(0); }

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

int factorial(int n) {
    if (n < 0) {
        return -1; // Error condition
    }
    if (n == 0) {
        return 1;
    }

    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    int fact = factorial(n);

    if (n == 0) {
    }

    if (n == 1) {
    }

    if (n == 2) {
    }

    if (n == 3) {
    }

    // Factorial grows fast, we assert legality for small values
    if (n <= 3) {
        __VERIFIER_assert(fact != -1);
    }

    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}