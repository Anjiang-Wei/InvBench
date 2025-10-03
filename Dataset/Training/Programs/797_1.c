/*
 * Program to simulate a linear recurrence relation.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "recurrence.c", 4, "reach_error"); }
extern void abort(void);
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 50); // Assume some reasonable bounds for N

    int a = 1;
    int b = 1;
    int c = 1;

    int i;

    for (i = 0; i < N; i++) {
        int new_c = a + b + c;
        a = b;
        b = c;
        c = new_c;
    }

    // Check that the final value of c is an odd number
    __VERIFIER_assert(c % 2 == 1);

    return 0;
}