/*
Series of Squares
computes the sum of squares: sum(i^2)[i=1..N]
uses loop to accumulate the value and verify constraints
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "series_squares.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int square(unsigned int x) {
    return x * x;
}

int main() {
    unsigned int N, i;
    unsigned long long sum, expected_sum;

    N = __VERIFIER_nondet_uint();

    sum = 0;
    expected_sum = 0;

    for (i = 1; i <= 100; i++) {
        if (i <= N) {
            sum += square(i);
            expected_sum += i * i;
        }
    }

    // Verify that the computed sum equals the mathematically expected one
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}