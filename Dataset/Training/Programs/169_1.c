// sum_cubes_relation.c
// Verifies that 1^3 + 2^3 + ... + k^3 == (1 + 2 + ... + k)^2

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_cubes_relation.c", 9, "reach_error");
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
    int k = __VERIFIER_nondet_int();
    /* restrict k so that sums and squares fit in 64-bit */
    assume_abort_if_not(k >= 0 && k <= 1000);

    int c = 1;
    long long sum = 0;
    long long sum_cubes = 0;

    while (c <= k) {
        sum += c;
        sum_cubes += (long long)c * c * c;
        /* check the well‐known identity at each step */
        __VERIFIER_assert(sum_cubes == sum * sum);
        c++;
    }

    /* final check */
    return 0;
}