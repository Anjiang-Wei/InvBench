#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
    int limit, multiplier;
    int sum = 0;
    int count;

    // Get nondeterministic inputs for limit and multiplier
    limit = __VERIFIER_nondet_int();
    multiplier = __VERIFIER_nondet_int();

    // Ensure the inputs meet certain conditions
    assume_abort_if_not(limit > 0);
    assume_abort_if_not(multiplier > 1);

    // Process numbers till the sum reaches the limit
    for (count = 1; sum < limit; count++) {
        sum += multiplier;

        // Assertion to ensure sum is greater than or equal to zero
        __VERIFIER_assert(sum >= 0);
    }

    // Final check to ensure sum has overshot the limit

    printf("Total numbers processed: %d\n", count);
    printf("Final sum: %d\n", sum);
    return 0;
}