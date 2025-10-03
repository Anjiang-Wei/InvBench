#include <assert.h>

// Simulating an external symbolic input function
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

// Function to simulate error reaching
void reach_error(void) {
    assert(0);
}

// Custom assertion check
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Program to verify if a pattern of increasing integers is followed by a specific decremental condition
int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int limit = 5; // limiting the values for the loop
    int sum = 0;

    // Initial constraints for verification
    if (!(a > 0 && b > 0 && c == 0)) {
        return 0;
    }

    // Loop with meaningful computation
    for (int i = 0; i < limit; i++) {
        c += a + b; // entity increases steadily
        sum += c;   // cumulative sum accumulation
    }

    // Condition enforced after loop
    int expected_sum = c * limit - ((limit - 1) * limit / 2) * (a + b); // reverse calculate based on arithmetic progression
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}