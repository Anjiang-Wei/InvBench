#include <stdio.h>
#include <stdlib.h>

// Simulation of external, nondeterministic functions
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Return a random number between 0 and 99
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error(void) {
    printf("Error reached\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int m, n;
    long sum = 0;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && n > 0 && m < 50 && n < 50);

    // Intended to compute the sum of numbers up to n and extends to m iterations
    int i = 0;
    while (i < m) {

        if (!(i < n)) {
            break;
        }

        sum += i;
        i++;
    }

    // Verifying at the completion of the loop
    __VERIFIER_assert(sum == (i * (i - 1)) / 2);
    return 0;
}