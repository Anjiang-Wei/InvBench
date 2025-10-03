/*
 * New Example Program:
 * Fibonacci Series with Loop and Constraint Conditions
 */

#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 30) {
        return 1; // Ensure n is within a safe range
    }

    int fib0 = 0;
    int fib1 = 1;
    int fib = 0;

    if (n == 0) {
        fib = fib0;
    } else if (n == 1) {
        fib = fib1;
    } else {
        int i = 2;
        while (i <= n) {
            fib = fib0 + fib1;
            fib0 = fib1;
            fib1 = fib;
            i++;
        }
    }

    // Constraint: The nth Fibonacci number should be less than or equal to 832040 for n <= 30
    __VERIFIER_assert(fib <= 832040);

    return 0;
}