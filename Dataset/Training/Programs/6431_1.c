#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "binary_sqrt.c", 3, "reach_error");
}

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
    int A = __VERIFIER_nondet_int();
    /* we only handle non-negative inputs */
    assume_abort_if_not(A >= 0);

    int low = 0;
    int high = A;
    int res = 0;

    /* Binary search for the integer floor of sqrt(A) */
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sq = (long long)mid * mid;
        if (sq <= A) {
            /* mid is a valid candidate */
            res = mid;
            low = mid + 1;
        } else {
            /* mid*mid > A, too large */
            high = mid - 1;
        }
    }

    /* After the loop, res = floor(sqrt(A)) */
    __VERIFIER_assert((long long)res * res <= A);

    return 0;
}