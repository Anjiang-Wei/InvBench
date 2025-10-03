#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_prog.c", 4, "reach_error"); }
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

int main() {
    int max_iterations, sum, step;
    long long product;

    max_iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(max_iterations > 0 && max_iterations <= 1000);

    sum = 0;
    product = 1;
    step = 0;

    while (1) {
        if (!(step < max_iterations)) {
            break;
        }

        sum += step;
        product *= (step + 1);
        step++;

        // Checker for interim conditions
    }

    // Final check to ensure loop invariant-like properties
    __VERIFIER_assert(sum == (step * (step - 1)) / 2);

    // Another check to ensure no overflow (for demonstration purpose)
    assume_abort_if_not(product >= 0);

    return 0;
}