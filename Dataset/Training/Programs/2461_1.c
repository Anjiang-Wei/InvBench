extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sumcubes.c", 7, "reach_error");
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
    /* pick a non‐negative n up to a reasonable bound */
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000);

    int i = 1;
    long long sum_lin = 0;
    long long sum_cubes = 0;

    /* Compute sum of first n integers and sum of their cubes */
    while (i <= n) {
        sum_lin += i;
        sum_cubes += (long long)i * i * i;
        i++;
    }

    /* Verify the known identity: 1^3 + 2^3 + ... + n^3 == (1 + 2 + ... + n)^2 */
    __VERIFIER_assert(sum_cubes == sum_lin * sum_lin);

    return 0;
}