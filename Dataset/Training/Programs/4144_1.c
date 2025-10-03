/*
Fibonacci Series Computation
This program computes the nth Fibonacci number using a loop
and checks certain mathematical properties of Fibonacci numbers.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 6, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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

unsigned int fib(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    unsigned int prev = 0, curr = 1, next;
    for (unsigned int i = 2; i <= n; ++i) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    unsigned int n;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting n for verification purposes

    unsigned int result = fib(n);

    // Verify a known property of Fibonacci numbers:
    // Until the 10th Fibonacci number, F(n) <= F(n-1) + F(n-2)
    if (n >= 2) {
        unsigned int fn_1 = fib(n - 1);
        unsigned int fn_2 = fib(n - 2);
        __VERIFIER_assert(result == fn_1 + fn_2);
    }

    return 0;
}