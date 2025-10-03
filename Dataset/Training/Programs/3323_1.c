#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    if (n <= 0 || m <= 0) {
        return 0; // Exit if inputs are non-positive
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }

    int product = 1;
    for (int j = 1; j <= m; j++) {
        product *= j;
        if (product > 1000) {
            break; // Avoid overflow for large m
        }
    }

    // Verify some conditions
    __VERIFIER_assert(sum >= 0);

    // Output the results
    printf("Sum of numbers from 0 to %d is: %d\n", n - 1, sum);
    printf("Product of numbers from 1 to %d is: %d\n", m, product);

    return 0;
}