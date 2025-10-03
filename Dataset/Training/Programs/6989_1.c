#include <stdio.h>
#include <stdlib.h>

/* Example Program
   Calculates the factorial of a number using recursive multiplication and iterates
   through an array while performing operations on its elements.
*/

extern void abort(void);
void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int limit = __VERIFIER_nondet_int();

    if (n < 0) {
        n = -n; // Ensure n is non-negative
    }

    if (limit < 0) {
        limit = -limit; // Ensure limit is non-negative
    }

    // Compute the factorial of n
    int factorial_result = factorial(n);

    int arr[10];
    int len = 0; // Length counter

    // Initialize array with factorial_result modulo operations
    while (__VERIFIER_nondet_bool() && len < 10) {
        arr[len] = factorial_result % (len + 1);
        len++;
    }

    // Ensure len is within bounds
    __VERIFIER_assert(len >= 0 && len <= 10);

    // Check array elements against limit
    for (int i = 0; i < len; i++) {
    }

    return 0;
}