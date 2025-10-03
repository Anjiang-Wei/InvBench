#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main(void) {
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;

    // Nondeterministic choice for loop limit
    unsigned int N = __VERIFIER_nondet_uint();
    assume_abort_if_not(N >= 5 && N <= 10); // Constraint on N

    while (a < N) {
        a += 1;
        b += a;
        c = 2 * b - a; // A derived relation
    }

    // Constraint expected to hold after loop termination
    __VERIFIER_assert(c >= b);

    printf("Final values: a = %u, b = %u, c = %u\n", a, b, c);
    return 0;
}