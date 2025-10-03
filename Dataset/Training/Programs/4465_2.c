#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Program to solve Fibonacci sequence using iterative approach
    Precondition: n >= 0
    Postcondition: fib_n is the nth Fibonacci number
*/

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    // Initial conditions
    int fib_n = 0;
    int prev = 1;
    int current = 0;
    int i = 0;

    while (i < n) {
        fib_n = prev + current;
        prev = current;
        current = fib_n;
        i++;
    }

    // Assertion to verify the final computed Fibonacci number
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(fib_n == 1);
    }

    return 0;
}