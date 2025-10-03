#include <assert.h>
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error(void) { __assert_fail("0", "new_program.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* This program models a basic Fibonacci series calculation.
   The user inputs a number `n`, and the program calculates the sum
   of the first `n` Fibonacci numbers.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    int a = 0, b = 1, fib_sum = 0, i;

    if (n < 0) {
        return 0; // Precondition: n has to be non-negative
    }

    for (i = 0; i < n; i++) {
        fib_sum += a;
        int tmp = a + b;
        a = b;
        b = tmp;
    }

    // Postcondition: The sum of the first n Fibonacci numbers is non-negative
    __VERIFIER_assert(fib_sum >= 0);

    return 0;
}