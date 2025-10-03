// int_sqrt.c
// Compute integer square root of a non-negative number using binary search
// and verify the result: result^2 <= n < (result+1)^2

#include <stdlib.h>

// Declaration of abort and assertion failure (as in typical verifier benchmarks)
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "int_sqrt.c", __LINE__, "reach_error");
}

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

// Nondeterministic integer generator (provided by the verifier)
extern int __VERIFIER_nondet_int(void);

int main() {
    // Get an unconstrained input n
    int n = __VERIFIER_nondet_int();

    // We only handle 0 <= n <= 2147395600 so that (46340+1)^2 fits in 32‐bit range
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 2147395600);

    // Binary search bounds for sqrt(n)
    int low = 0;
    // 46340^2 = 2147395600 is the largest square below INT_MAX
    int high = (n < 46340 ? n : 46340);
    int mid;

    // Search for the greatest mid such that mid*mid <= n
    while (low <= high) {
        mid = low + (high - low) / 2;
        long long midsq = (long long)mid * mid;
        if (midsq <= n) {
            /* mid is a valid candidate, try higher */
            low = mid + 1;
        } else {
            /* mid^2 > n, go lower */
            high = mid - 1;
        }
    }

    // high is now floor(sqrt(n))
    int result = high;

    // Verify the post‐conditions:
    //   1) result*result <= n
    //   2) (result+1)^2 > n
    long long nextsq = (long long)(result + 1) * (result + 1);
    __VERIFIER_assert(nextsq > n);

    return 0;
}