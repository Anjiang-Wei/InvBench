// sum_cubes.c
// Verifies that the sum of the first N cubes equals (1 + 2 + … + N)^2

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_cubes.c", 6, "reach_error"); }

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
    // nondeterministic bound
    int N = __VERIFIER_nondet_int();
    // we constrain N to a reasonable non-negative range
    assume_abort_if_not(N >= 0 && N <= 10000);

    long long sum = 0;
    long long cubes = 0;

    // Compute sum = 1 + 2 + ... + N
    //        cubes = 1^3 + 2^3 + ... + N^3
    for (int i = 1; i <= N; ++i) {
        sum += i;
        cubes += (long long)i * i * i;
    }

    // Verify the known identity: 1^3 + 2^3 + ... + N^3 == (1 + 2 + ... + N)^2
    __VERIFIER_assert(cubes == sum * sum);

    return 0;
}