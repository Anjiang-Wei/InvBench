#include <stdio.h>

/*
Factorial Calculation using Iterative Method
This program calculates the factorial of a number n.
It uses an iterative loop to compute the factorial.
*/

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n;
    long long factorial = 1;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // To ensure no integer overflow for factorial

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    // To ensure factorial was computed correctly, verify a simple condition
    if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}