// New C Program with Verification Constraints

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_nested_loop.c", 15, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
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

// This program calculates a bounded series where each term is processed within a nested structure.
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 1 && m <= 5);

    int sum = 0;
    int i, j;

    // A nested loop structure that processes 'm' different series' sums
    for (i = 0; i < m; ++i) {
        int series_sum = 0;

        // Each series is a geometric series of terms up to 'n'
        for (j = 0; j < n; ++j) {
            series_sum += j * i;
        }

        sum += series_sum;
    }

    // Check that the computed sum follows specific rules
    if (m >= 2 && n >= 2) {
        assume_abort_if_not(sum > 0);
    }

    __VERIFIER_assert(sum >= 0);

    return sum; // Return the sum for further verification.
}