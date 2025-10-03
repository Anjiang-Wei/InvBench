#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
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
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 5); // Limiting n for verification purposes

    int sum = 0;
    int factorial = 1;
    int i;

    for (i = 1; i <= n; i++) {
        factorial *= i; // Compute factorial iteratively
        sum += i * i;   // Sum up squares of integers

        if (i % 2 == 0) { // Introduce some conditional logic
            sum -= i;
        }
    }

    // Verification to check the relationship between the computed values
    // Do not specify loop invariant; rather check final state conditions
    // and implicit computational result of the program.
    __VERIFIER_assert(sum >= 0 && factorial > 0);

    printf("Final sum: %d\n", sum);
    printf("Final factorial: %d\n", factorial);

    return 0;
}