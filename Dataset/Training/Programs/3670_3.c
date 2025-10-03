#include <assert.h>
#include <stdlib.h>

// Function to simulate a failure condition.
void reach_error(void) {
    assert(0);
}

// Function to assert a condition, and call reach_error if the condition is not met.
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate a non-deterministic integer.
extern int __VERIFIER_nondet_int(void);

// Function to simulate a non-deterministic boolean.
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    // Initialize non-deterministic values
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();

    // Ensure some initial conditions
    if (!(a >= 0 && b > 0 && c == 0 && d == 0)) {
        return 0;
    }

    // A loop that increments c and d based on conditions
    while (__VERIFIER_nondet_bool()) {
        if (a > 0) {
            d += a;
            c++;
        } else {
            d -= b;
        }

        // Ensuring the values remain within certain bounds

        // Randomly modify a and b to simulate conditions.
        a += __VERIFIER_nondet_int() % 2;
        b += __VERIFIER_nondet_int() % 2;
    }

    // Post conditions
    __VERIFIER_assert(c >= 0);

    return 0;
}