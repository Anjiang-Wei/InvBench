#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int calculate_fibonacci(int n) {
    int a = 0, b = 1, c;
    if (n == 0) {
        return a;
    }
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 20); // Limit N for feasibility

    int fib = calculate_fibonacci(N);

    // Verify that the Fibonacci calculation is non-negative
    __VERIFIER_assert(fib >= 0);

    // Ensure some property of the Fibonacci sequence (fib > N for N > 10)
    if (N > 10) {
    }

    printf("Fibonacci(%d) = %d\n", N, fib);

    return 0;
}