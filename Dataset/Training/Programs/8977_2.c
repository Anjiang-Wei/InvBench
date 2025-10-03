#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int x, y, z, sum;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && y >= 0);

    z = 0;
    sum = 0;

    // Start of loop construct
    while (z < y) {
        sum = sum + x + z;
    }

    __VERIFIER_assert(sum == x * y + y * (y - 1) / 2); // Final check after the loop
    printf("Sum: %d\n", sum);
    return 0;
}