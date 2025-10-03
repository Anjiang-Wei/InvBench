#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
}

int main() {
    int a, b, sum = 0, product = 1;
    int limit = __VERIFIER_nondet_int();

    // Set constraints on limit
    assume_abort_if_not(limit >= 1 && limit <= 10);

    // Loop for summing numbers and checking product property
    for (a = 1; a <= limit; a++) {
        sum += a;
        product *= a;

        // Invariant: Every step, product should be positive
        __VERIFIER_assert(product > 0);
    }

    // Check a property at the end
    b = (limit * (limit + 1)) / 2; // Known sum of first limit natural numbers

    // Print computed values for manual verification
    printf("Computed sum: %d, expected sum: %d\n", sum, b);
    printf("Computed product: %d\n", product);

    return 0;
}