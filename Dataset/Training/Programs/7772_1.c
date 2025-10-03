#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int calculate_factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);  // Assume n is a non-negative integer
    assume_abort_if_not(n <= 12); // Restrict n to prevent integer overflow on factorial

    int fact = calculate_factorial(n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // If n > 0 and fact is less than a threshold that can be hard for a verification tool to detect easily without loop invariants.
    if (n > 0 && fact > 479001600) {
        reach_error();
    }

    // We assert that the sum of the first n integers is n * (n + 1) / 2 which is a known formula.
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    return 0;
}