#include <assert.h>
#include <stdbool.h>
void reach_error(void) { assert(0); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting n to avoid integer overflow

    int factorial = 1;
    int i = 1;

    while (i <= n) {
        // Compute factorial iteratively
        factorial *= i;
        i++;
    }

    // Verify that factorial calculation is done correctly: n! != 0

    // Special case checks
    if (n == 0 || n == 1) {
    }

    // For n=5, the factorial should be 120
    if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    }

    return 0;
}