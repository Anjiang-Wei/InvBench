#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int a, b, n, diff;
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();
    n = __VERIFIER_nondet_uint();

    assume_abort_if_not(a >= 0 && b >= 0 && n >= 0 && n <= 100);

    diff = (a > b) ? (a - b) : (b - a);

    unsigned int counter = 0;

    // Progressively reduce the difference
    while (diff > 0 && counter < n) {
        if (diff % 2 == 0) {
            diff /= 2; // Halve the difference if it's even
        } else {
            diff -= 1; // Decrease the difference by 1 if it's odd
        }
        counter++;
    }

    // After the loop, diff should not be negative and should be less than or equal to its original value

    // Ensure loop runs correctly and doesn't exceed bounds
    __VERIFIER_assert(counter <= n);

    printf("End: difference = %u, counter = %u\n", diff, counter);
    return 0;
}