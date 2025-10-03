#include <stdio.h>
#include <stdlib.h>

/*
Arithmetic Sequence and Cube Calculation
Compute an arithmetic sequence and then calculate the cube of the sum,
verifying specific properties along the way.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 7, "reach_error"); }

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
}

int main() {
    int a, d, n;
    long long sum, cube_sum;
    a = __VERIFIER_nondet_int();
    d = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(d >= 0 && d <= 10);
    assume_abort_if_not(n >= 1 && n <= 20);

    sum = 0;
    cube_sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a + i * d;
    }

    cube_sum = sum * sum * sum;

    // Verify that the cube of the sum is a non-negative number
    // (which is trivially true given the constraints, but a useful check)
    __VERIFIER_assert(cube_sum >= 0);

    // Print results for demonstration purposes (not typically used in verification)
    printf("Arithmetic series starting at %d with difference %d for %d terms gives sum %lld\n", a, d, n, sum);
    printf("The cube of the sum is %lld\n", cube_sum);

    return 0;
}