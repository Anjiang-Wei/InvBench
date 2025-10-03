/*
A simple program that calculates the factorial of a given number n
and verifies the result using multiplication. The check is done using
a secondary loop that multiplies numbers from 1 to n, ensuring it matches the calculated factorial.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_check.c", 12, "reach_error"); }
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
    return;
}

int counter = 0;
unsigned int factorial(unsigned int n) {
    unsigned int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    unsigned int n = 5; // A specific number to calculate the factorial
    unsigned int fact = factorial(n);

    unsigned int check = 1;
    unsigned int i = 1;

    while (i <= n) {
        check *= i;
        i++;
    }

    __VERIFIER_assert(fact == check);
    printf("Factorial of %u is %u\n", n, fact);
    return 0;
}