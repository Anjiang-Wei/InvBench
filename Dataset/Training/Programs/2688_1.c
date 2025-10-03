#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

#define LIMIT 100000

int main() {
    int n, a, b, c;
    n = __VERIFIER_nondet_int();

    // Assume n is within a certain limit for safety
    if (n <= 0 || n > LIMIT) {
        return 0;
    }

    a = 0;
    b = 0;
    c = 0;

    while (a < n) {
        b += 2;
        if (b % 5 == 0) {
            c++;
        }
        a++;
    }

    // Check a derived property
    __VERIFIER_assert(c == b / 10);

    return 0;
}