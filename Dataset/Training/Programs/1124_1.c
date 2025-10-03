#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int a = 0;
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int limit = 100;

    assume_abort_if_not(b > 0);
    assume_abort_if_not(c > 0);

    // Calculate the greatest common divisor using Euclid's algorithm
    while (b != c) {
        if (b > c) {
            b = b - c;
        } else {
            c = c - b;
        }
        a++;
        if (a > limit) {
            // To prevent infinite loop in case of any unexpected behavior
            break;
        }

        __VERIFIER_assert(b > 0 && c > 0); // Ensuring the values never become zero
    }

    // Post-condition: The result should be the greatest common divisor
    int gcd = b;

    // Print result for verification
    printf("GCD is %d\n", gcd);
    return 0;
}