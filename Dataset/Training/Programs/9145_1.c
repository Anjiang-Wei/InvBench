#include <assert.h>
#include <stdio.h>

// Function prototypes for external functions
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

// We define a function to simulate a verification error
void reach_error() { assert(0); }

// Custom assert function using reach_error
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// New C Program based on the learned patterns
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assume valid initial conditions
    if (!(a >= 0 && b == c && c > 0)) {
        return 0;
    }

    int sum = 0;
    int product = 1;

    while (__VERIFIER_nondet_bool()) {
        if (b <= 0) {
            break;
        }

        sum += b;
        product *= c;

        a = a + 1;
        b = b - 1;
    }

    // Post-condition checks
    __VERIFIER_assert(a >= 0);

    return 0;
}