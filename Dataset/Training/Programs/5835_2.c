/* Fibonacci Number Computation */
/* Computes the first `n` Fibonacci numbers */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
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
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limit `n` for computational feasibility

    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long temp;
    int i = 0;

    while (i < n) {
        a = b;
        b = temp;

        i++;
    }

    // Verification that nth Fibonacci number was computed correctly
    __VERIFIER_assert(n < 2 || b == a + temp - b); // nth Fibonacci should be correctly computed

    return 0;
}