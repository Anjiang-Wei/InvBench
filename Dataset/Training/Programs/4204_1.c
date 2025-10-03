#include <stdio.h>
#include <stdlib.h>

// Declare external functions and helpers for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a < 100);
    assume_abort_if_not(b >= 0 && b < 100);

    int sum = 0;
    int product = 1;

    // Loop that computes sum and product of non-deterministically chosen numbers
    for (int i = 0; i < 10; i++) {
        int num = __VERIFIER_nondet_int();
        assume_abort_if_not(num >= 0 && num < 50);

        sum += num;
        product *= (num + 1);

        // Assertion to check a specific condition on sum and product
        __VERIFIER_assert(sum <= 500 && product > 0);
    }

    // Final assertion to ensure sum and product meet expected conditions

    return 0;
}