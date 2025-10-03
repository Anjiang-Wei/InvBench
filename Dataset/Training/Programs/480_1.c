// sum of cubes equals square of sum: verification benchmark

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_cubes.c", 8, "reach_error");
}

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 10000);

    long long sum = 0;
    long long sum_cubes = 0;

    for (int i = 1; i <= N; i++) {
        sum += i;
        sum_cubes += (long long)i * i * i;
    }

    // Mathematical fact: 1^3 + 2^3 + ... + N^3 == (1 + 2 + ... + N)^2
    __VERIFIER_assert(sum_cubes == sum * sum);

    return 0;
}