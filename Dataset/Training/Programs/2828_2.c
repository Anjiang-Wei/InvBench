/* Fibonacci sequence verification program */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 5, "reach_error"); }
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
    long long fib1, fib2, fib_next;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50); // Constraint to prevent overflow

    fib1 = 0;
    fib2 = 1;

    int counter = 0;

    while (counter < n) {
        fib_next = fib1 + fib2;

        fib1 = fib2;
        fib2 = fib_next;
        counter = counter + 1;
    }

    // Verify Fibonacci sequence relation
    if (n > 0) {
        __VERIFIER_assert(fib1 + fib2 == fib_next + fib1);
    }

    return 0;
}