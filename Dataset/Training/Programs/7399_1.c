#include <stdio.h>

extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int size = __VERIFIER_nondet_int();

    // Assume that size must be positive and no greater than 100
    assume_abort_if_not(size > 0 && size <= 100);

    int sum = 0;
    int product = 1;
    int i;
    _Bool condition = __VERIFIER_nondet_bool();

    int numbers[size];
    // Initialize array elements to nondeterministic values
    for (i = 0; i < size; i++) {
        numbers[i] = __VERIFIER_nondet_int();
    }

    // If the condition is true, compute sum; otherwise compute product
    if (condition) {
        for (i = 0; i < size; i++) {
            sum += numbers[i];
        }
        // Verify that sum is greater than an arbitrary threshold
        assume_abort_if_not(sum > 10);
    } else {
        for (i = 0; i < size; i++) {
            product *= numbers[i];
        }
        // Verify that product is not zero
        assume_abort_if_not(product != 0);
    }

    // Final assertions to check computation validity
    __VERIFIER_assert((condition && sum > 10) || (!condition && product != 0));

    return 0;
}