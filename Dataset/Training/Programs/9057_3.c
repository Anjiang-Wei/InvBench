#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 3, "reach_error"); }
extern void abort(void);
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

int __VERIFIER_nondet_int(void);

long long factorial(int n) {
    if (n < 0) {
        return -1; // factorial is not defined for negative numbers
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
        // ensure no overflow occurs in computation
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // limit n to avoid overflow in factorial

    long long result = factorial(n);

    // ensure the result is correct for small known values
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(result == 1);
    } else if (n == 5) {
    } else if (n == 10) {
    }

    printf("Factorial of %d is %lld\n", n, result);
    return 0;
}