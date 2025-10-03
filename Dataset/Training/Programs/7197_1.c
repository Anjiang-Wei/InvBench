/*
Fibonacci Series Verification
This program computes the Fibonacci series up to the N-th term (N ≥ 2).
The program verifies that the N-th term is the sum of the (N-1)-th and (N-2)-th terms,
which is a characteristic property of the Fibonacci sequence.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 13, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 2 && N <= 20);

    long long fib[N];
    fib[0] = 0;
    fib[1] = 1;

    int i;
    for (i = 2; i < N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Verify that fib[N-1] = fib[N-2] + fib[N-3] for N ≥ 3
    if (N >= 3) {
        __VERIFIER_assert(fib[N - 1] == fib[N - 2] + fib[N - 3]);
    }

    return 0;
}