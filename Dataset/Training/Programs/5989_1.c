// This program is part of a learning exercise for automatic verification tools.
// It contains a loop with increment operations and a constraint that is checked
// at the end using assertions.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "increment_constraint.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = 0;
    int b = __VERIFIER_nondet_int();

    // Assume b is between 1 and 10 for the loop to execute several times
    if (b < 1 || b > 10) {
        return 0;
    }

    // Loop that modifies 'a' based on the value of 'b'
    while (b > 0) {
        a = a + b;
        b = b - 1;
    }

    // Verification condition for 'a'
    __VERIFIER_assert(a > 0 && a <= 55); // 1+2+...+10 == 55 is the largest sum possible

    return 0;
}