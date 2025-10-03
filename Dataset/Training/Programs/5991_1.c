/*
Fibonacci Sequence Verification
Computes the Fibonacci sequence iteratively and verifies a property of the sequence.
The property: for n >= 3, Fib(n) / Fib(n-1) approaches the golden ratio (approximately 1.618),
here we verify that it is greater than or equal to 1.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 3 && n <= 20);

    long long fib_n_2 = 0; // F(n-2)
    long long fib_n_1 = 1; // F(n-1)
    long long fib_n = 0;
    int i = 2;

    while (i <= n) {
        fib_n = fib_n_1 + fib_n_2;

        // Verify the ratio property, assuming n is sufficiently large
        // Actually testing for n >= 3 here:
        if (i >= 3) {
            __VERIFIER_assert(fib_n * fib_n_2 <= fib_n_1 * fib_n_1 + fib_n_1 * fib_n_2);
        }

        fib_n_2 = fib_n_1;
        fib_n_1 = fib_n;
        i++;
    }

    printf("Fib(%d) = %lld\n", n, fib_n);
    return 0;
}