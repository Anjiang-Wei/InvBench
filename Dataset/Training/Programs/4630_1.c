/*
   Fibonacci Sequence Computation
   Computes the nth Fibonacci number using iteration
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-iterative.c", 10, "reach_error"); }
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
    long long fib, fib_prev1, fib_prev2, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    fib_prev1 = 0;
    fib_prev2 = 1;
    fib = 0;

    if (n == 0) {
        fib = 0;
    } else if (n == 1) {
        fib = 1;
    } else {
        fib_prev1 = 0;
        fib_prev2 = 1;

        for (i = 2; i <= n; i++) {
            fib = fib_prev1 + fib_prev2;
            fib_prev1 = fib_prev2;
            fib_prev2 = fib;
        }
    }

    __VERIFIER_assert(fib >= 0);

    return 0;
}