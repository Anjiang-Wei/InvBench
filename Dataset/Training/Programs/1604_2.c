#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume initial constraints
    assume_abort_if_not(n > 0 && n < 100); // Ensure n is a positive number less than 100
    assume_abort_if_not(a >= 0 && b >= 0); // Ensure a and b are non-negative integers

    int sum = 0;
    int product = 1;

    // Factorial-like computation based on n
    int i = 1;
    while (i <= n) {
        sum += i;     // Calculate the sum of the first n natural numbers
        product *= i; // Calculate the factorial-like product
        i++;
    }

    // At this point, we have: sum (1 to n) = n*(n+1)/2 and product = n!
    __VERIFIER_assert(product >= 1); // Simple check if product is greater than zero

    return 0;
}