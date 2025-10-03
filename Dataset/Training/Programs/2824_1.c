#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
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

int main() {
    // Variable declarations
    int a = 0, b = 0, c = 0;
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    a = 1;
    b = 2;
    c = 3;

    // Loop that modifies variables
    while (a < n) {
        a = a + b;
        b = b + c;
        c = c + a;

        if (b > 50) {
            break;
        }
    }

    // Final check
    __VERIFIER_assert(a < 1000 && b < 1000 && c < 1000);

    // Print final values for debugging purposes
    printf("Final values are: a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}