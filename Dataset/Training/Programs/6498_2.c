#include <assert.h>
#include <stdlib.h>

extern void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assumption_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (!(a >= 0 && b > 0)) {
        return 0; // Assume a and b must meet this initial condition
    }

    int sum = 0;
    while (a < b) {
        sum += a;
        a++;
        if (a % 2 == 0) {
            sum -= (a / 2);
        }
    }

    // Adding some verification conditions
    __VERIFIER_assert(sum >= 0); // Ensure the sum never becomes negative

    return 0;
}