/*
 * A C program that computes the sum of the first N natural numbers and
 * the sum of their cubes, then verifies the well-known identity:
 *    (1 + 2 + ... + N)^2 == 1^3 + 2^3 + ... + N^3
 * The program is designed for verification by automated tools
 * using __VERIFIER_assert and assume_abort_if_not.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_cubes_identity.c", 12, "reach_error");
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();

    // We require N to be positive and not too large to avoid overflow
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 10000);

    long long sum1 = 0; // will hold 1 + 2 + ... + N
    long long sum3 = 0; // will hold 1^3 + 2^3 + ... + N^3
    int i;

    for (i = 1; i <= N; i++) {
        sum1 += i;
        sum3 += (long long)i * i * i;
    }

    // Check the identity: (sum1)^2 == sum3
    __VERIFIER_assert(sum3 == sum1 * sum1);

    return 0;
}