// New C program demonstrating alternating sums and non-trivial constraints
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "alternating_sum.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i, sum, element;

    // Assume n is a nondeterministic integer between 1 and 100
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100);

    sum = 0;

    // Loop for alternating sum computation
    for (i = 0; i < n; i++) {
        element = __VERIFIER_nondet_int();
        assume_abort_if_not(element >= -50 && element <= 50); // Elements are constrained between -50 and 50

        if (i % 2 == 0) {
            sum += element; // Add on even index
        } else {
            sum -= element; // Subtract on odd index
        }
    }

    // Verify some property about the sum
    __VERIFIER_assert(sum >= -5000 && sum <= 5000);
    return 0;
}