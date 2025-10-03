#include <assert.h>
#include <stdio.h>
extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int fib = 0, prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
    }
    return fib;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 10) {
        // Limiting the input for verification purposes
        return 0;
    }
    int result = fibonacci(n);
    printf("Fibonacci of %d is %d\n", n, result);

    // Verify some known Fibonacci values
    if (n == 0) {
        __VERIFIER_assert(result == 0);
    }
    if (n == 1) {
    }
    if (n == 5) {
    }
    if (n == 10) {
    }

    return 0;
}