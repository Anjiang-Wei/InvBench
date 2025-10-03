// Your complete C program here
// A C program suitable for automated verification tools.
// It computes the sum of the first n integers, the sum of their squares,
// and then the sum of their cubes, checking key polynomial invariants
// without explicitly revealing the loop invariants.

#include <stdint.h>

// Verification harness declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("error", "sum_squares_cubes.c", 10, "reach_error");
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

// Entry point
int main() {
    // Read a non-deterministic n
    int n = __VERIFIER_nondet_int();
    // We only handle 0 <= n <= 1000 to keep arithmetic in bounds
    assume_abort_if_not(n >= 0 && n <= 1000);

    // Variables for first loop: computing sum_{i=1..n} i  and sum_{i=1..n} i^2
    int i = 0;
    long long sum = 0;
    long long sqsum = 0;
    int count1 = 0;

    // First loop: iterate count1 from 0 to n
    while (count1 < n) {
        // Check invariants relating sum and sqsum to count1
        // 2 * sum == count1 * (count1 + 1)
        // 6 * sqsum == count1 * (count1 + 1) * (2*count1 + 1)

        // Body: increment and accumulate
        count1++;
        sum += count1;
        sqsum += (long long)count1 * count1;
    }

    // Post-loop checks for first loop
    __VERIFIER_assert(2LL * sum - (long long)count1 * (count1 + 1) == 0);

    // Variables for second loop: computing sum_{i=1..count1} i^3
    int j = 0;
    long long cubesum = 0;
    int count2 = 0;
    // We will check: 4*cubesum == [count1*(count1+1)]^2

    while (count2 < count1) {
        // Check invariant for cubesum
        long long lhs = 4LL * cubesum;
        long long rhs = (long long)count2 * (count2 + 1);
        rhs = rhs * rhs; // square of count2*(count2+1)

        // Body: advance and accumulate
        count2++;
        cubesum += (long long)count2 * count2 * count2;
    }

    // Final checks for second loop
    {
        long long lhs = 4LL * cubesum;
        long long rhs = (long long)count2 * (count2 + 1);
        rhs = rhs * rhs;
    }

    // A third loop: accumulate alternating sum of integers up to n
    // alt_sum = 1 - 2 + 3 - 4 + ... +/- n
    int k = 0;
    long long alt_sum = 0;
    int sign = 1; // +1 or -1
    int count3 = 0;

    while (count3 < n) {
        // Check a simple relation: at any point,
        // alt_sum == (count3+1)/2 if count3 is odd else -(count3/2)
        long long expected;
        if ((count3 % 2) == 0) {
            expected = (long long)(count3 / 2) * -1;
        } else {
            expected = (long long)((count3 + 1) / 2);
        }

        // Body: advance and accumulate alternating term
        count3++;
        k = count3;
        alt_sum += sign * (long long)k;
        sign = -sign;
    }
    // Final check for third loop
    {
        long long expected;
        if ((count3 % 2) == 0) {
            expected = (long long)(count3 / 2) * -1;
        } else {
            expected = (long long)((count3 + 1) / 2);
        }
    }

    return 0;
}