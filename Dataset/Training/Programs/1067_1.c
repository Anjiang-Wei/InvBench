#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 1000); // Assume a reasonable bound to prevent overflows

    long long factorial = 1;
    int i;

    for (i = 2; i <= n; i++) {
        factorial *= i;
    }

    // Verify that the factorial computation didn't overflow for numbers less than or equal to 20
    // Factorial of 20 is 2432902008176640000, which fits in a 64-bit integer
    if (n <= 20) {
        __VERIFIER_assert(factorial > 0);
    }

    return 0;
}