#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    unsigned int sum_a = 0, sum_b = 0;
    unsigned int i = 0, a = 0, b = 1;

    while (i < n) {
        if (i % 3 == 0) {
            a += 1;
            sum_a += i;
        }
        if (i % 5 == 0) {
            b += 1;
            sum_b += i;
        }

        i++;
        assume_abort_if_not(sum_a >= a * (a - 1) / 2); // Ensure arithmetic sum correctness
        assume_abort_if_not(sum_b >= b * (b - 1) / 2); // Ensure arithmetic sum correctness
    }

    // After the loop, arithmetic series sums are expected
    __VERIFIER_assert(sum_a == (a * (a - 1)) / 2);

    return 0;
}