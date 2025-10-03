/*
Computes the sum of the first n odd numbers
and verifies the result is equal to n^2
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "odd_sum.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i;
    long long sum, expected;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    expected = (long long)n * n;

    for (i = 1; i <= n; i++) {
        sum += 2 * i - 1; // Sum of first n odd numbers
    }

    __VERIFIER_assert(sum == expected);

    return 0;
}