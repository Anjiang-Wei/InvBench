/*
Program to compute Fibonacci-like sequence and verify conditions.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_like.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int seed1, seed2, bound;
    long long a, b, c;

    // Random nondeterministic integers with constraints
    seed1 = __VERIFIER_nondet_int();
    assume_abort_if_not(seed1 >= 1 && seed1 <= 10);

    seed2 = __VERIFIER_nondet_int();
    assume_abort_if_not(seed2 >= 1 && seed2 <= 10);

    bound = __VERIFIER_nondet_int();
    assume_abort_if_not(bound >= 20 && bound <= 30);

    a = (long long)seed1;
    b = (long long)seed2;
    c = 0;

    int iteration = 0;
    while (iteration < bound) {
        b = c;

        iteration++;
    }

    // Final assertion to ensure sequence properties
    __VERIFIER_assert((c == a + b) || (c == a) || (c == b));

    printf("Last terms: a = %lld, b = %lld, c = %lld\n", a, b, c);
    return 0;
}