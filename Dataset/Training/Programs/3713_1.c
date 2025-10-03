// Sum of cubes equals square of sum verification
// Computes sum_{i=1..k} i^3 and sum_{i=1..k} i, then checks sum_cubes == (sum_i)^2

#include <limits.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_cubes_square.c", 10, "reach_error"); }

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
    int k = __VERIFIER_nondet_int();
    // bound k so the loop is finite and arithmetic stays in range
    assume_abort_if_not(k >= 0 && k <= 10000);

    long long sum_cubes = 0;
    long long sum_i = 0;
    int i = 1;

    // accumulate sum of i^3 and sum of i
    while (i <= k) {
        sum_cubes += (long long)i * i * i;
        sum_i += (long long)i;
        i++;
    }

    // check the well‐known identity: (1^3 + 2^3 + ... + k^3) == (1 + 2 + ... + k)^2
    __VERIFIER_assert(sum_cubes == sum_i * sum_i);

    return 0;
}