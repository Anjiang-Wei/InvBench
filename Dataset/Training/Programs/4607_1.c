#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int n;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 10);

    int result = fib(n);

    int counter = 0;
    int sum = 0;

    // Loop to calculate the sum of all Fibonacci numbers up to the result
    while (counter <= result) {
        sum += fib(counter);
        counter++;
    }

    // Assert that sum is greater than or equal to result
    __VERIFIER_assert(sum >= result);

    printf("Fibonacci of %d is %d\n", n, result);
    printf("Sum of Fibonacci numbers up to %d is %d\n", result, sum);

    return 0;
}