#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

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
    int x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 100);
    int i = 0;
    int sum = 0;
    int product = 1;

    // Perform some computations with loop and conditions
    while (i < x) {
        sum += i;
        product *= (i + 1);
        i++;

        // Some verification constraints
        if (i % 10 == 0) {
        }
    }

    // Adding final assertions
    __VERIFIER_assert(product > 0);

    return 0;
}