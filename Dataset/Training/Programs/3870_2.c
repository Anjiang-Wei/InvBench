#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() {
    assert(0);
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
    int product = 1;

    // Ensure a and b start within reasonable bounds
    if (!(a >= 0 && a <= 10 && b >= 0 && b <= 10)) {
        return 0;
    }

    // Perform calculations until one of the values reaches a certain bound
    while (a < 15 && b < 15) {
        sum = sum + a + b;           // calculate sum of integers 'a' and 'b'
        product = product * (a + 1); // calculate product (factorial-like growth)

        // Ensure that product never becomes zero (avoid multiplication with zero)

        if (__VERIFIER_nondet_bool()) {
            a++;
        } else {
            b++;
        }
    }

    // Post-condition check: Verify that we've hit one of the loop bounds
    __VERIFIER_assert(a == 15 || b == 15);

    printf("Final sum: %d, Final product: %d\n", sum, product);

    return 0;
}