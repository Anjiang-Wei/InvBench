/*
Compute the factorial of a number using multiplication while maintaining constraints on the operations
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial-constraints.c", 5, "reach_error"); }
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
    int n, i;
    long long factorial, prev_factorial;
    n = __VERIFIER_nondet_int();

    // Assume n is non-negative and small enough to avoid overflow
    assume_abort_if_not(n >= 0 && n <= 12);

    factorial = 1;
    prev_factorial = 1;

    for (i = 1; i <= n; ++i) {
        prev_factorial = factorial;
        factorial *= i;

        // Verification constraint: Check multiplication consistency

        // Verification constraint: Ensure factorial is always non-negative
        __VERIFIER_assert(factorial >= 0);
    }

    // Additional post-loop verification constraint
}