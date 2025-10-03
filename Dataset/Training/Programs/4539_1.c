#include <stdio.h>
#include <stdlib.h>
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) {
    printf("Error reached\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
The Fibonacci sequence F(n) is defined as follows:
- F(0) = 0
- F(1) = 1
- For n > 1: F(n) = F(n-1) + F(n-2)

This program calculates the Fibonacci number for a given `n` using a loop,
and ensures that the result is greater than or equal to the largest number
in the sequence up to `n-1`.

precondition: n >= 0
loopcondition: i <= n
loop: compute Fibonacci sequence
postcondition: fib_n >= F(n-1)
*/
int main() {
    int n = __VERIFIER_nondet_int();
    if (!(n >= 0)) {
        return 0; // Precondition
    }

    int fib_n = 0;    // F(0)
    int fib_prev = 1; // F(1)
    int i = 2;

    if (n == 0) {
        fib_n = 0;
    } else if (n == 1) {
        fib_n = 1;
    } else {
        while (i <= n) {
            int temp = fib_n;
            fib_n = fib_n + fib_prev;
            fib_prev = temp;
            i++;
        }
    }

    if (n > 1) {
        __VERIFIER_assert(fib_n >= fib_prev);
    }

    printf("Fibonacci of %d is %d\n", n, fib_n);
    return 0;
}