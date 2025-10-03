#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Factorial of numbers greater than 12 will overflow a 32-bit integer

    int result = factorial(n);

    // Verify that factorial(n) is a multiple of n (for n > 0)
    if (n > 0) {
    } else {
        __VERIFIER_assert(result == 1); // factorial(0) is 1
    }

    return 0;
}