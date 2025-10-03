#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// This program implements a simple linear congruential generator (LCG) for pseudo-random numbers
// and verifies some properties of the generated sequence.
int main() {
    int a = 1664525;
    int c = 1013904223;
    int m = 4294967296; // 2^32
    int seed = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int i;

    // Seed and size constraints
    assume_abort_if_not(n > 0 && n <= 1000); // reasonable size limits
    assume_abort_if_not(seed > 0 && seed < m);

    int *sequence = malloc(sizeof(int) * n);
    if (!sequence) {
        return 1; // allocation failed
    }

    sequence[0] = seed;
    for (i = 1; i < n; i++) {
        sequence[i] = (a * sequence[i - 1] + c) % m;
    }

    // Verifying that all numbers are within expected range of 0 and m-1
    for (i = 0; i < n; i++) {
    }

    // Simple property: Check average value should not exceed m/2
    long long sum = 0;
    for (i = 0; i < n; i++) {
        sum += sequence[i];
    }

    __VERIFIER_assert(sum / n < m / 2);

    free(sequence);
    return 0;
}