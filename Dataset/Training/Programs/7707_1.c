extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Helper function to assert conditions, which simulates verification checks
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = 0;
    int b = 0;
    int n = __VERIFIER_nondet_int();

    // Assume a valid range for n
    assume_abort_if_not(n >= 0 && n <= 100);

    // Loop with simple computation
    int i = 0;
    while (i < n) {
        a += i * i; // Accumulate square of i
        if (i % 2 == 0) {
            b += i; // Keep a separate sum of even numbers
        }
        i++;
    }

    // For verification purposes, we expect b to be less than or equal to a
    __VERIFIER_assert(b <= a);

    // The main iterative computation checks are complete
    return 0;
}