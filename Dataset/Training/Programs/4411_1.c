/* Fibonacci series computation with verification */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
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
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // Ensure n is non-negative

    long long fib0 = 0, fib1 = 1;
    long long fibN = 0;
    int i = 0;

    if (n == 0) {
        fibN = 0;
    } else if (n == 1) {
        fibN = 1;
    } else {
        fibN = fib1;
        i = 2;
        while (i <= n) {
            long long temp = fibN;
            fibN = fib0 + fib1;
            fib0 = fib1;
            fib1 = fibN;
            i++;
        }
    }

    // Assert that the computed Fibonacci number is non-negative
    __VERIFIER_assert(fibN >= 0);
    return 0;
}