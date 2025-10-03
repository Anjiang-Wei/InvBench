#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume meaningful constraints for verification
    assume_abort_if_not(a > 0 && b > 0 && n > 0);
    assume_abort_if_not(n < 100);

    int sum = 0;
    int product = 1;
    int i;

    // Summation loop with boundary condition
    for (i = 0; i < n; i++) {
        sum += a;
    }

    // Accumulative product loop with controlled iterations
    for (i = 0; i < n; i++) {
        product *= b;
        if (product > 1000) {
            product = 1000;
        }
    }

    __VERIFIER_assert(sum >= 0);

    // Output results
    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}