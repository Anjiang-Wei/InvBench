#include <stdio.h>
#include <stdlib.h>

// Helper functions and verifiers (based on patterns from the given examples)
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

extern void abort(void);
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

extern int __VERIFIER_nondet_int(void);

// New proposed C program
int main() {
    int a, b, c, d, limit;
    a = b = c = d = 1;
    limit = __VERIFIER_nondet_int();

    // Constraint to limit the nondeterministic choice
    assume_abort_if_not(limit >= 1 && limit <= 10);

    // Loop to perform some iterative computation
    while (a < limit) {
        b *= 2;
        c += a;
        d += b - c;
        a++;

        // Perform assertions using upstream properties
        __VERIFIER_assert(b % 2 == 0);
    }

    // Final assertions to check overall computation

    return 0;
}