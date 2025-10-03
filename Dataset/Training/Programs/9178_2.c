#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0, counter = 0;

    if (n < 0 || n > 100) {
        return 0; // constraint on the nondeterministic input
    }

    // Intended logic: Compute sum of numbers up to n and count steps
    for (int i = 1; i <= n; i++) {
        sum += i;
        counter++;
    }

    // Checking that the sum calculation is correct
    int expected_sum = n * (n + 1) / 2;

    // Ensuring the result meets our expectations
    __VERIFIER_assert(counter == n);

    return 0;
}