#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int m, n;
    long long a, b;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure that m and n are within certain bounds to prevent overflows
    assume_abort_if_not(m > 0 && m <= 50);
    assume_abort_if_not(n > 0 && n <= 50);

    a = 0;
    b = 0;

    // Series generation with multiplication logic
    while (m > 0) {
        a = a + n;
        b = b + a * a;

        if (m % 2 == 0) {
            a = a - 1;
        }

        m--;

        // Constraint condition
    }

    __VERIFIER_assert(b >= a * n);

    return 0;
}