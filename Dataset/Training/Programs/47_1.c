#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
    return;
}

// Represents a nondeterministic value, for the purpose of verification tools
int __VERIFIER_nondet_int() {
    return rand() % 21; // Simulates a nondeterministic choice between 0 and 20
}

int compute(int n) {
    int sum = 0;
    // Loop that accumulates value only if n is positive
    for (int i = 0; i < n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (!(0 <= n && n <= 20)) {
        return 0;
    }

    int result = compute(n);
    int expected_sum = (n * (n - 1)) / 2;

    // Assert that the computed sum is as expected
    __VERIFIER_assert(result == expected_sum);

    return 0;
}