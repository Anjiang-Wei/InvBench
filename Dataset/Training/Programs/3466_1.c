#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() {
    assert(0);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int steps = 0;

    // Constraint: Both a and b should be non-negative and less than 1000
    assume_abort_if_not(a >= 0 && a < 1000);
    assume_abort_if_not(b >= 0 && b < 1000);

    // Loop through numbers from 0 to a
    while (steps < a) {
        sum += steps * b; // Sum multiples of b as we move through the loop
        steps++;
    }

    // We know that for positive a, sum will be a triangular number times b
    __VERIFIER_assert(sum >= 0); // Asserting non-negativity of sum

    printf("a: %d, b: %d, sum: %d\n", a, b, sum);
    return 0;
}