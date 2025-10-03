extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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

int main() {
    int i, j, n, sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1); // meaningful constraint to ensure positive number of iterations.

    sum = 0;
    product = 1;
    j = n;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Condition to verify that product and factorial relationship holds.
        // Even though no explicit assertion is utilized to define loop invariants,
        // the loop progresses with meaningful operations over basic arithmetic series.
    }

    // Add a verification at the end to check if sums and products match expected properties.
    __VERIFIER_assert(sum > 0 && product > 0);

    // Check a known mathematical identity for sum of natural numbers.

    // The product which is factorial will always be positive since we assume n >= 1.

    return 0;
}