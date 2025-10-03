#include <stdio.h>

// Dummy verification functions
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, n;
    long long sum_aSq, sum_bCube, iterate;

    // Generate non-deterministic input
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Validation of inputs
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(n >= 0 && n <= 100);

    sum_aSq = 0;
    sum_bCube = 0;
    iterate = 0;

    // Compute squares sum and cubes sum
    while (iterate < n) {
        sum_aSq += (a + iterate) * (a + iterate);
        sum_bCube += (b + iterate) * (b + iterate) * (b + iterate);

        iterate++;

        // Verification pattern adapted
    }

    // Conclude final verification checks after loop
    __VERIFIER_assert(sum_aSq >= 0);

    printf("Sum of squares till n: %lld\n", sum_aSq);
    printf("Sum of cubes till n: %lld\n", sum_bCube);

    return 0;
}