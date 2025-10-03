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
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int i;

    assume_abort_if_not(a > 0 && a < 100);
    assume_abort_if_not(b > 0 && b < 100);

    int sum = 0;
    int product = 1;
    int iterations = __VERIFIER_nondet_int();

    assume_abort_if_not(iterations > 0 && iterations <= 10);

    for (i = 0; i < iterations; i++) {
        sum += a;
        product *= b;
    }

    // Constraint checking outside the loop
    __VERIFIER_assert(sum >= a * iterations);

    // Log the values for verification tools
    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}