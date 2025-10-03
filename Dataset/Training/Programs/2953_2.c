#include <assert.h>
#include <stdlib.h>

// Mock function to simulate nondeterministic integer input
int __VERIFIER_nondet_int(void) {
    return rand() % 20; // Returns a random number between 0 and 19
}

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define MAX_ITER 100

int main() {
    int i;
    int a, b;

    // Get nondeterministic values for a and b
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    if (!(1 <= a && a <= 10 && 1 <= b && b <= 10)) {
        return 0;
    }

    int sum = 0;
    for (i = 0; i < MAX_ITER; i++) {
        sum += a - b;

        // To prevent infinite loop in case of incorrect logic
        if (i == MAX_ITER - 1) {
        }
    }

    // Final assertion to verify a condition based on the loop's logic
    __VERIFIER_assert(sum == (a - b) * MAX_ITER);

    return 0;
}