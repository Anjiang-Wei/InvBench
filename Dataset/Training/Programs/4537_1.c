/*
Fibonacci Series Verification
Computes Fibonacci numbers up to a specified index n
Returns the nth Fibonacci number
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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
int counter = 0;

int main() {
    int n;
    long long fib_n, fib_n_minus_1, fib_n_minus_2;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 50); // To avoid overflow in Fibonacci computation

    fib_n_minus_1 = 0; // Fibonacci(0)
    fib_n = 1;         // Fibonacci(1)

    if (n == 0) {
        fib_n = 0;
    }

    int i = 2;
    while (counter++ < 1) {
        if (!(i <= n)) {
            break;
        }

        fib_n_minus_2 = fib_n_minus_1;
        fib_n_minus_1 = fib_n;
        fib_n = fib_n_minus_1 + fib_n_minus_2;

        i = i + 1;
    }

    __VERIFIER_assert(fib_n == (n <= 1 ? n : fib_n_minus_1 + fib_n_minus_2));
    printf("Fibonacci(%d) = %lld\n", n, fib_n);

    return 0;
}