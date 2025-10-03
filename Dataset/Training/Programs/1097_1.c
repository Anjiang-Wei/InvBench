#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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
    int x, z;
    long long y, sum;
    x = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    // Initial assumptions
    assume_abort_if_not(x >= 0 && z >= 0);

    y = 1;
    sum = 0;

    while (y <= x + z) {
        // Simple computational logic: accumulate sum of squares
        sum += y * y;
        y++;
    }

    // Simple condition: check if the sum is non-negative
    __VERIFIER_assert(sum >= 0);

    // Output the results for verification
    printf("Computed sum of squares from 1 to %d is %lld\n", x + z, sum);

    return 0;
}