// Sum of Cubes Equals Square of Sum
// This program computes S = sum_{i=1..N} i
// and C = sum_{i=1..N} i^3 in one loop, then checks that
// C == S*S, a known mathematical identity.
// It is written for verification by automated tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_cubes_eq_square.c", 10, "reach_error");
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
    // We only consider non-negative N up to a bound to avoid overflow
    if (N < 0) {
        return 0;
    }
    assume_abort_if_not(N <= 10000);

    long long sum = 0;
    long long sumCube = 0;

    for (int i = 1; i <= N; i++) {
        sum += i;
        sumCube += (long long)i * i * i;
    }

    // Check the identity: (1 + 2 + ... + N)^2 == 1^3 + 2^3 + ... + N^3
    __VERIFIER_assert(sumCube == sum * sum);
    return 0;
}