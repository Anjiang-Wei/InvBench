#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int main() {
    int x, y, z;
    long long sum;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(x > 0 && y > 0 && z > 0);

    sum = 0;
    // A loop that computes the weighted sum of x multiples
    for (int i = 0; i < 100; ++i) {
        __VERIFIER_assert(i >= 0);

        if (i % 10 == 0 && i != 0) {
            // Introduce a multiplier at every 10th step
            sum += (x * y * (i / 10));
        }
        sum += x;

        // Check some condition at various iterations
        if (sum > z) {
            break;
        }
    }

    // Assert to check if the sum is within a certain range

    return 0;
}