#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
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

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 20); // to avoid extremely large computations
    int i, sum = 0;

    for (i = 0; i <= N; i++) {
        int f = fib(i);
        sum += f;
        // Assert that the sum of the first i Fibonacci numbers is greater than or equal to the i-th Fibonacci number
        __VERIFIER_assert(sum >= f);
    }

    printf("Sum of first %d Fibonacci numbers is: %d\n", N, sum);
    return 0;
}