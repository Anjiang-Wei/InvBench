/*
 * Sum of Cubes Verification
 * Verifies the identity: 1^3 + 2^3 + ... + N^3 = (1 + 2 + ... + N)^2
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_cubes.c", 10, "reach_error");
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        /* ERROR */
        { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    /* Bound N to avoid overflow in 64-bit arithmetic */
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 10000);

    long long sum = 0;
    long long cubesum = 0;
    int i;

    for (i = 1; i <= N; i++) {
        sum += i;
        cubesum += (long long)i * i * i;
    }

    /* Final verification: sum of cubes equals square of sum */
    __VERIFIER_assert(cubesum == sum * sum);

    return 0;
}