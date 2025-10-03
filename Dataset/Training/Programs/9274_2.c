#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
void reach_error(void) {
    printf("Error reached\n");
    exit(1);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = a + b;
    int sum = 0;

    // Precondition
    if (a < 0 || b < 0 || a > 100 || b > 100) {
        return 0;
    }

    // Loop to increment `sum`
    // Here we mimic a condition that depends on non-determinism
    // but guarantees progress towards termination.
    int counter = 0;
    while (__VERIFIER_nondet_bool() && counter < 10) {
        sum += (a % 3) + (b % 3);
        counter++;
    }

    // Ensure the sum is greater than or equal to the initial combined modulo values

    // Another simple loop
    int x = 0;
    for (int i = 0; i < 10; i++) {
        x += (a + b) % 10;
    }

    // Post-condition
    __VERIFIER_assert(x == 10 * ((a + b) % 10));

    return 0;
}