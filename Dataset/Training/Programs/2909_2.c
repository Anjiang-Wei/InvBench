#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 4, "reach_error"); }
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

int main() {
    int a = 0, b = 0, n = 10; // You can change 'n' to a nondeterministic value if necessary
    int i, sum = 0;

    // Loop to calculate the sum of the first n natural numbers
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    // Post-condition: The sum of the first n natural numbers is n*(n+1)/2

    // A loop to find the maximum between two numbers
    while (a <= b) {
        a = __VERIFIER_nondet_int();
        b = __VERIFIER_nondet_int();

        if (a > b) {
            break;
        }
    }

    // Post-condition: 'a' should be greater than 'b'
    __VERIFIER_assert(a > b);

    return 0;
}