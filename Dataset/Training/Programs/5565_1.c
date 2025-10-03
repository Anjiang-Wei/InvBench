#include <stdio.h>
#include <stdlib.h>

/*
This program calculates two basic operations on numbers, namely factorial and Fibonacci series using loops and conditions.
The computation is controlled by some assertions and constraints,
making it a suitable candidate for automated verification tools.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 9, "reach_error"); }
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

unsigned int factorial(unsigned int n) {
    unsigned int result = 1;
    unsigned int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

unsigned int fibonacci(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    unsigned int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    unsigned int num1, num2, fact, fib;
    num1 = __VERIFIER_nondet_uint();
    assume_abort_if_not(num1 >= 0 && num1 <= 10); // limit input for factorial to avoid overflow
    num2 = __VERIFIER_nondet_uint();
    assume_abort_if_not(num2 >= 0 && num2 <= 30); // limit input for fibonacci

    fact = factorial(num1);
    fib = fibonacci(num2);

    // Some basic assertion to check if operations worked correctly
    __VERIFIER_assert(factorial(0) == 1);

    printf("Factorial of %u is %u\n", num1, fact);
    printf("Fibonacci of %u is %u\n", num2, fib);

    return 0;
}