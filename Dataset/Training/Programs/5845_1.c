#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
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
    int a, b, n;
    int sum, product, counter;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0);
    assume_abort_if_not(a >= 0 && b > 0);

    sum = 0;
    product = 1;
    counter = 0;

    while (counter < n) {
        // Perform some meaningful operations
        sum += a * counter;
        product *= b;
        counter++;

        // Constraint condition ensuring meaningful computation during iterations
        __VERIFIER_assert(sum >= 0 && product > 0);
    }

    // Final constraint checking after loop completion

    printf("Final Sum: %d, Final Product: %d\n", sum, product);
    return 0;
}