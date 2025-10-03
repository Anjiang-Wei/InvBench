#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Ensure n is in a reasonable range for demonstration purposes
    if (n <= 0 || n > 1000) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int i = 1;

    // Loop to compute the sum and product of integers from 1 to n
    while (i <= n) {
        sum += i;
        product *= i; // Will quickly grow large, but used for demonstration

        // Checkpoint assertion
        if (i % 100 == 0) {
            __VERIFIER_assert(sum > 0);
        }

        i++;
    }

    // Final assertion to check the sum of the first n natural numbers

    return 0;
}