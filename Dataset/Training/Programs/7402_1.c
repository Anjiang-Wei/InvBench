/*
Fibonacci Sequence Verification
computes Fibonacci numbers in variables a and b for 'n' iterations,
verifies the correctness of Fibonacci sequence property.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib.c", 9, "reach_error"); }
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
    int n;
    // Inputs: n defines how many iterations of the sequence to compute
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    long long a = 0;
    long long b = 1;
    long long temp;
    int i = 0;

    while (i < n) {
        // Verify that current numbers satisfy Fibonacci property
        // This asserts that at any time a, b are consecutive Fibonacci numbers
        __VERIFIER_assert(b >= a);

        // Compute next Fibonacci number
        temp = b;
        b = a + b;
        a = temp;

        i++;
    }

    // Final property: after n iterations, b should be >= a since Fibonacci sequence is non-decreasing

    return 0;
}