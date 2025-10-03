#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();
    int C = __VERIFIER_nondet_int();
    int D = __VERIFIER_nondet_int();

    // Initialize counters to be decremented
    int counterA = 10, counterB = 10, counterC = 10, counterD = 10;

    // Input flags
    _Bool flagA = __VERIFIER_nondet_bool(), flagB = __VERIFIER_nondet_bool();

    // Loop enforcing some constraints on counters
    while (counterA > 0 || counterB > 0 || counterC > 0 || counterD > 0) {
        if (flagA && counterA > 0) {
            counterA--;
        } else if (flagB && counterB > 0) {
            counterB--;
        } else if (counterC > 0) {
            counterC--;
        } else if (counterD > 0) {
            counterD--;
        }

        flagA = __VERIFIER_nondet_bool();
        flagB = __VERIFIER_nondet_bool();
    }

    // Assert conditions after loop
    __VERIFIER_assert(counterA == 0);

    return 0;
}