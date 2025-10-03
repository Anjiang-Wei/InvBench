#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 6, "reach_error"); }

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
    int m, n, sum, prod, counter;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume m and n are positive integers
    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    sum = 0;
    prod = 1;
    counter = 0;

    while (counter < n) {

        sum += counter;
        prod *= 2;
        counter++;

        if (prod >= 1024) {
            break;
        }
    }

    // Basic properties to check
    __VERIFIER_assert(sum >= 0);

    printf("Sum: %d, Product: %d, Counter: %d\n", sum, prod, counter);
    return 0;
}