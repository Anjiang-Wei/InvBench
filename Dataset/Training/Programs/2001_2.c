#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

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
    int c = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Initial assumptions
    if (!(a >= 0 && b >= 0 && c >= 0)) {
        return 0;
    }
    if (!(a < 1000 && b < 1000 && c < 1000)) {
        return 0;
    }

    // Loop with computation and constraints
    int count = 0;
    while (__VERIFIER_nondet_bool() && count < 10) {
        sum += a + b + c;
        product *= (a + 1);
        a += 1;
        b += 2;
        c += 3;
        count++;
    }

    // Postconditions to verify
    __VERIFIER_assert(product > 0);

    // Additional logical condition verification

    printf("Sum: %d, Product: %d, Count: %d\n", sum, product, count);
    return 0;
}