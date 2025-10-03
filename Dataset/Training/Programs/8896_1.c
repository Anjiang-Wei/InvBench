#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 30); // Limit the input to a reasonable number due to recursion
    long long sum = 0;

    // Calculating the sum of Fibonacci numbers up to n
    for (int i = 0; i <= n; ++i) {
        int fib = fibonacci(i);
        sum += fib;

        // Periodically check if our sum matches the sum of calculated Fibonacci numbers.
        __VERIFIER_assert(sum >= fib);
    }
}