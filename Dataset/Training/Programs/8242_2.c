/*
Program to compute the integer cube root of a non-negative number
The program estimates the floor of the cube root of an integer n.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "cube_root.c", 9, "reach_error"); }
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
    int n;
    long long low, high, mid, cube;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000000);

    low = 0;
    high = n;
    mid = 0;

    if (n == 0) {
        mid = 0; // the cube root of 0 is 0
    } else {
        while (low <= high) {
            mid = low + (high - low) / 2;
            cube = mid * mid * mid;

            if (cube == n) {
                break;
            } else if (cube < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // The position of mid when low > high will be a candidate for floor(cube root)
        mid = high;
    }

    printf("The floor of the cube root of %d is %lld\n", n, mid);

    // Final assertions
    __VERIFIER_assert((mid + 1) * (mid + 1) * (mid + 1) > n);

    return 0;
}