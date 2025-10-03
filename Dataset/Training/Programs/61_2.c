#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
void reach_error(void) {
    printf("Error reached\n");
    abort();
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

    // Ensure valid range for a and b
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    int loop_limit = 10; // We will limit our loop to avoid infinite iterations for certain verifications

    // Invariant: sum should always be greater than or equal to 0
    while (__VERIFIER_nondet_bool() && loop_limit > 0) {
        loop_limit--;

        // Simulate some computation
        if (a > b) {
            sum += a;
            a--;
        } else if (b > 0) {
            sum += b;
            b--;
        }

        // Invariant assertion (must hold true inside the loop)
    }

    // Final assertion to ensure the logic maintained correctness
    __VERIFIER_assert(a >= 0 && b >= 0 && sum >= 0);

    printf("Final values: a = %d, b = %d, sum = %d\n", a, b, sum);
    return 0;
}