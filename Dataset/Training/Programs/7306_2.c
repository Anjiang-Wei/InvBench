#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int a, b;
    long long m, n, temp;
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();

    // Constrain the values of a and b to a small range for the sake of demonstration
    assume_abort_if_not(a > 0 && a <= 2);
    assume_abort_if_not(b > 0 && b <= 2);

    m = 1;
    n = b;
    temp = 0;

    while (1) {
        // Verification loop invariant check

        if (temp >= a) {
            break;
        }

        temp += 1;
        m = m * b + 1;
        n = n * b;
    }

    // Transform m by a factor of b-1
    m = m * (b - 1);

    // Final check
    __VERIFIER_assert(1 + m - n == 0);

    return 0;
}