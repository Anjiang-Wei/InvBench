#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int perform_computation(int a, int b, int n) {
    int result = 0;
    int temp = a;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            temp += b;
        } else {
            temp -= b;
        }
    }

    result = temp * n;
    return result;
}

int main(void) {
    // Variable initialization
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (n < 0 || n > 100) {
        return -1; // Constraint for n
    }

    // Ensure a and b are within a specific range
    if (a < 0 || a > 1000) {
        return -1;
    }
    if (b < 0 || b > 1000) {
        return -1;
    }

    // Perform computation
    int result = perform_computation(a, b, n);

    // Assert condition
    __VERIFIER_assert(result >= 0);

    return 0;
}