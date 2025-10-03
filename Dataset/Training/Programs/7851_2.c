/*
 * New benchmark program for automated verification tools
 * Computes a sequence with specific properties and validates constraints
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_benchmark.c", 8, "reach_error");
}

extern void assume_abort_if_not(int cond) {
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

extern int __VERIFIER_nondet_int(); // Nondeterministic integer generator

int main() {
    int limit = __VERIFIER_nondet_int();

    if (limit <= 0) {
        return 1;
    }

    long long p = 1, q = 2;
    int i = 0;

    while (i < limit) {
        q = q + p;
        p = p * 2;
        i++;

        assume_abort_if_not(i < 1000000); // Ensure loop does not run indefinitely
    }

    // Constraint conditions to be checked by verification tools
    __VERIFIER_assert(2 * (p + q) > q);

    printf("Computation completed.\n");
    return 0;
}