#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int m = 0, n = 0;
    int sum = 0;

    // Initialize with arbitrary values that can be changed for verification
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure non-negative values for meaningful summation
    if (m < 0) {
        m = -m;
    }
    if (n < 0) {
        n = -n;
    }

    int i = 0;
    while (i < n) {
        sum += m;
        __VERIFIER_assert(sum == i * m + m);
        i++;
    }

    // After the loop, sum should be equal to m * n

    printf("Sum of %d added %d times is %d\n", m, n, sum);

    return 0;
}