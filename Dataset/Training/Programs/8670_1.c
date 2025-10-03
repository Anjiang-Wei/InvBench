// Sum of Cubes and Verification
// This program checks if the sum of cubes for a natural number series equals the square of the sum of the numbers.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sumsquares.c", 5, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);
void *malloc(unsigned int size);

int N;

int main() {
    N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000); // Prevent overly large numbers

    long long sum_cubes = 0;
    long long sum_nums = 0;
    int i;

    for (i = 1; i <= N; i++) {
        sum_cubes += (long long)i * i * i;
        sum_nums += i;
    }

    long long sum_nums_squared = sum_nums * sum_nums;

    __VERIFIER_assert(sum_cubes == sum_nums_squared);

    return 0;
}