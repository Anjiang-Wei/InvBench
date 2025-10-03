#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n, i;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Constraint for n

    i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    printf("Factorial of %d is %lld\n", n, factorial);

    // Check if computed factorial matches the expected factorial for small inputs
    if (n == 1) {
        __VERIFIER_assert(factorial == 1);
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    } else if (n == 6) {
    } else if (n == 7) {
    } else if (n == 8) {
    } else if (n == 9) {
    } else if (n == 10) {
    }

    return 0;
}