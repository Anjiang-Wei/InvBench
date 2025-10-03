#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int X = __VERIFIER_nondet_int();
    assume_abort_if_not(X >= 0 && X <= 100);

    // Ensure that X is not a perfect cube
    int cube_root = 1;
    while (cube_root * cube_root * cube_root <= X) {
        cube_root++;
    }
    assume_abort_if_not(cube_root * cube_root * cube_root > X);
    cube_root--;

    // Compute the sum of first N odd numbers using a loop
    int N = cube_root;
    int cumulative_sum = 0;
    int i;
    for (i = 0; i < N; ++i) {
        // Each odd number is of the form 2i + 1
        cumulative_sum += (2 * i + 1);
    }

    // The sum of the first N odd numbers should equal N^2
    __VERIFIER_assert(cumulative_sum == N * N);

    return 0;
}