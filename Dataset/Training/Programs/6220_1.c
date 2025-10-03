#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int sum = 0;

    assume_abort_if_not(n > 0);
    assume_abort_if_not(a > 0 && b > 0);

    while (n > 0) {
        sum += a * b; // sum is repeatedly increased by the product of a and b
        n--;
    }

    // Here we verify that if n was originally positive, the sum should have increased
    __VERIFIER_assert(sum > 0);

    printf("Sum: %d\n", sum); // Output the final sum

    return 0;
}