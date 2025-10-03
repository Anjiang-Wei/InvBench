#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_program.c", __LINE__, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    int x = n;
    int y = 0;
    int sum = 0;

    // Loop that will perform operations on `x`, `y` and `sum`
    while (x > 0) {
        y = y + 2;
        x--;

        // Loop-embedded condition to manipulate an accumulator
        if (y % 3 == 0) {
            sum += y;
        }

        // Ensure invariant properties after each iteration
        __VERIFIER_assert(sum >= 0);
    }

    // Final assertion to check desired end condition

    // Print sum to ensure side-effect
    printf("Sum: %d\n", sum);

    return 0;
}