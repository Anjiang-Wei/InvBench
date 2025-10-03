#include <stdio.h>
#include <stdlib.h>

/* Stub functions provided for verification tools */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

/* Assume function to decide program path in verification environment */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Function to execute assertions */
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, x, y, z;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensure inputs meet certain criteria
    assume_abort_if_not(a > 0 && a < 100); // a should be between 1 and 99
    assume_abort_if_not(b > 0 && b < 100); // b should be between 1 and 99

    x = a;
    y = b;
    z = 0;

    while (x != y) {
        __VERIFIER_assert(x >= 0 && y >= 0);

        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }

        z++;
    }

    // Check that the loop correctly computes the GCD

    printf("The GCD of %d and %d is %d\n", a, b, z);

    return 0;
}