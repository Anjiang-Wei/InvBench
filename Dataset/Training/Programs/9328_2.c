#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int n, a, b, c;
    n = __VERIFIER_nondet_int();

    a = 2;
    b = 3;
    c = a + b;

    while (1) {

        if (!(c < n)) { // Loop terminates when n is reached or exceeded
            break;
        }

        int prevC = c;
        c = a + b;
        a = b;
        b = prevC;
    }

    __VERIFIER_assert(c >= a && c >= b); // Ensure c holds the maximum value in the sequence

    return 0;
}