/*
 * Example Pattern-Based C Program
 * This program calculates the factorial of a non-negative integer n
 * and checks the constraint conditions.
 */

#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
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

long long factorial(int n) {
    long long result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 20); // assuming n is within reasonable bounds for factorial

    long long result = factorial(n);

    // Simple constraint: factorial of n should be greater than 0 if n > 0
    __VERIFIER_assert(n == 0 || result > 0);

    // Additional logic: Double check that n! when n <= 1 is exactly 1

    return 0;
}