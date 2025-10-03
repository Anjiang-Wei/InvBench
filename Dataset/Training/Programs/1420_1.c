/*
  Fibonacci Sequence Generator
  Computes the nth Fibonacci number iteratively
*/

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-ll.c", 8, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 46); // To prevent integer overflow for Fibonacci numbers

    int fib1 = 0;
    int fib2 = 1;
    int fibonacci = 0;
    int i = 0;

    if (n == 0) {
        fibonacci = 0;
    } else if (n == 1) {
        fibonacci = 1;
    } else {
        i = 2;
        while (i <= n) {
            fibonacci = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibonacci;
            i++;
        }
    }

    printf("Fibonacci number %d is %d\n", n, fibonacci); // To verify the result
    __VERIFIER_assert(fibonacci >= 0);                   // Simple assertion to ensure non-negative result

    return 0;
}