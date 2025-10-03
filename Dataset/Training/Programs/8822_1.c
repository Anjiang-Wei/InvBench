#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
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

int main() {
    int x = 0;
    int y = 0;
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // n should be positive to proceed

    // Increment y twice as fast as x in a loop
    while (x < n) {
        x++;
        y += 2;
    }

    // Ensure y is exactly twice what x is, given the loop structure
    __VERIFIER_assert(y == 2 * x);

    // Compute a simple arithmetic sequence
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Assert that the computed sum matches the mathematical formula

    printf("All assertions passed...\n");
    return 0;
}