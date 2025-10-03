#include <stdio.h>
#include <stdlib.h>

// Assertion mechanism
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
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

// Main logic
int main() {
    int a, b, n;
    int sum, product;
    int counter = 0;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    sum = 0;
    product = 1;

    while (counter++ < 20) {
        // Constrain a and b to be non-negative for meaningful computation
        assume_abort_if_not(a >= 0);
        assume_abort_if_not(b >= 0);

        if (!(a < n)) {
            break;
        }

        sum = sum + (a + b);
        product = product * (a + 1);

        a++;
    }

    // The post-loop condition assertion ensuring logical relationships hold
    __VERIFIER_assert(sum >= 0);

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}