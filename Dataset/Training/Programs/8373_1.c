// C Program that performs a constrained computation with automated verification potential.

#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    // Precondition: Assume a is non-negative and b is non-negative
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    int max_iterations = a + b;
    // Loop to calculate the sum of a and b
    for (int i = 0; i < max_iterations; ++i) {
        if (i < a) {
            sum++;
        }
        // Artificially add to b in remaining iterations
        else if (i < b + a) {
            sum++;
        }
    }

    // Postcondition: at the end sum should be a + b
    __VERIFIER_assert(sum == a + b);

    return 0;
}