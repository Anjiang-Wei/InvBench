// Verifies that the sum of cubes from 1 to N equals the square of the sum from 1 to N.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_cubes.c", 6, "reach_error");
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
    int N = __VERIFIER_nondet_int();
    /* we restrict N to avoid overflow of long long */
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 10000);

    long long sum1 = 0; /* will accumulate 1 + 2 + ... + N */
    long long sum3 = 0; /* will accumulate 1^3 + 2^3 + ... + N^3 */

    int i;
    for (i = 1; i <= N; i++) {
        sum1 += i;
        sum3 += (long long)i * i * i;
    }

    /* By a well‐known formula, (1 + 2 + ... + N)^2 == 1^3 + 2^3 + ... + N^3 */
    __VERIFIER_assert(sum3 == sum1 * sum1);

    return 0;
}