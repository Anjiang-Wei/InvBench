#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "my_program.c", __LINE__, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int a, b, c;
    int result = 0;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume certain constraints to make it suitable for verification tools
    assume_abort_if_not(a >= 0 && b >= 0);
    assume_abort_if_not(a <= 10000 && b <= 10000);

    // Initialize variables
    result = 0;
    c = 0;

    // Loop containing some computation
    while (c < a) {
        if (c % 2 == 0) {
            result += (c + b) / 2;
        } else {
            result -= (c + b) / 3;
        }

        c++;
    }

    // Assert a condition
    __VERIFIER_assert(result >= 0);

    printf("Result: %d\n", result);
    return 0;
}