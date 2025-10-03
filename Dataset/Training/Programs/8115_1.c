#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 9, "reach_error");
}

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
    int target, sum, number;
    target = __VERIFIER_nondet_int(); // Target sum that should be achieved
    assume_abort_if_not(target >= 0); // The target should be non-negative

    sum = 0;
    number = 0;

    while (1) {
        if (sum >= target) {
            break;
        }

        number += 1;
        sum += number;

        // The sum of first 'n' natural numbers is n*(n+1)/2
        // Ensure that manually adding does not surpass
        // the formula result
        __VERIFIER_assert(sum == (number * (number + 1)) / 2);
    }

    // Once the loop is terminated, the sum must be at least
    // the target.

    printf("Achieved target: %d with sum: %d\n", target, sum);

    return 0;
}