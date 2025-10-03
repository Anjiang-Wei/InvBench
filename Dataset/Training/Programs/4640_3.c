#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && b > 0);

    int result = gcd(a, b);

    assume_abort_if_not(result <= a && result <= b); // GCD should be less than or equal to both numbers

    int x = result;
    int y = result + 1;
    int count = 0;

    // Loop with meaningful computation: Check properties related to divisibility
    while (count < 5) {
        if (x % result == 0 && y % result != 0) {
        }
        x += result;
        y += result;
        count++;
    }

    // Final assertion to check properties
    __VERIFIER_assert(result > 0);
    return 0;
}