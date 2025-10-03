#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Declare variables
    int a = 0;
    int b = __VERIFIER_nondet_int();                // Represents some input value
    int c = __VERIFIER_nondet_int();                // Another input to simulate different paths
    int d = 0;                                      // Counter
    _Bool condition_met = __VERIFIER_nondet_bool(); // A symbolic condition

    // Precondition setup
    if (!(b >= 0)) {
        return 0;
    }

    // Loop to perform some computation
    while (__VERIFIER_nondet_bool() && d < 100) {
        a += b;
        if (condition_met) {
            a += c;
        }
        d++;
    }

    // Postcondition: Ensure a reaches or exceeds a certain threshold
    if (condition_met) {
        __VERIFIER_assert(a >= d * c); // This utilizes the inputs meaningfully
    } else {
        __VERIFIER_assert(a >= d * b);
    }

    return 0;
}