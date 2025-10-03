// New C Program

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

// Calculates the sum of a series and verifies a condition
int main() {
    int a, n;
    long long sum, term;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 10); // Assume range constraint on a
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Assume range constraint on n

    sum = 0;
    term = a;
    int i = 0;

    while (i < n) {
        sum += term;
        term *= 2; // Double the term in each iteration
        i++;
    }

    // Verify that the sum is equal to the expected computation of the series
    long long expected = a * ((1LL << n) - 1);
    __VERIFIER_assert(sum == expected);

    return 0;
}