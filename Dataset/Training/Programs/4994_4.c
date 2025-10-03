#include <stdio.h>

// Function declarations for external tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, a, b, z;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100); // Constrain n to be a manageable size
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 100); // Constrain m to be a manageable size
    assume_abort_if_not((n + m) % 2 == 0);   // Require n + m to be even

    a = 0;
    b = 0;
    z = 1;

    for (int i = 0; i < n; i++) {
        a += i;
        b += (i % 2 == 0 ? i * 2 : -i); // Adds varied computation pattern
        z *= 2;
    }

    // Dynamic computation based on new b value
    while (b > 0) {
        b -= z;
        z /= 2;
    }

    __VERIFIER_assert(z >= 0);

    printf("Computation complete with final values: a=%d, b=%d, z=%d\n", a, b, z);

    return 0;
}