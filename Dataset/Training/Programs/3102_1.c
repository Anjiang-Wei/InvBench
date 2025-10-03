extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    int sum_squares = 0;
    int modified_sum = 0;

    // Assumption to avoid overflow and keep it within bounds
    assume_abort_if_not(n >= 1 && n <= 1000);

    unsigned int i = 0;
    while (i < n) {
        int val = __VERIFIER_nondet_int();
        assume_abort_if_not(val >= -100 && val <= 100);

        sum_squares += val * val;
        modified_sum += val * ((i % 2 == 0) ? 1 : -1); // Alternating sum

        i++;
    }

    // Verification condition: sum of squares should be non-negative
    // the absolute value of the modified sum cannot be greater than sum_squares
    __VERIFIER_assert(sum_squares >= 0);

    return 0;
}