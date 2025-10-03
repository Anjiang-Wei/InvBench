#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Limiting n to prevent integer overflow

    int calculated_factorial = 1;
    int expected_factorial = factorial(n);

    int i = 1;
    while (i <= n) {
        calculated_factorial *= i;
        i++;
    }

    // Check if our computed factorial matches the one computed via the recursive function
    __VERIFIER_assert(calculated_factorial == expected_factorial);

    return 0;
}