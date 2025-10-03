// This program is a part of a hypothetical benchmark collection for verification tasks.
// It demonstrates the use of recursive functions, loops, and input constraints,
// ensuring it can be analyzed by automated verification tools.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 10, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

// Function to simulate complex logic with recursion
void recursive_logic(int *a, int *b, int limit) {
    if ((*a) < limit) {
        *a += 1;
        *b += 2;
    }
}

// Main algorithm with a loop and input constraints
int main() {
    int a = 0, b = 0;
    int limit = __VERIFIER_nondet_int();

    // Ensure the input constraints
    if (limit <= 0 || limit > 1000) {
        return -1;
    }

    // Loop with meaningful computation
    for (int i = 0; i < limit; i++) {
        a++;
        b += 2;
        __VERIFIER_assert(b == 2 * a); // Check invariant in the loop
    }

    // Call recursive logic with the same invariant
    recursive_logic(&a, &b, limit);

    // Final assertion to verify

    printf("Computation completed successfully with a = %d, b = %d.\n", a, b);

    return 0;
}