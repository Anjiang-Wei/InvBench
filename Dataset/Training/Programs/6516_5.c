#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);

    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0);

    int sum = 0;
    int product = 1;
    int count = 0;

    while (count < a) {
        sum += (b + count);
        product *= (count + 1);

        // Conditions to ensure we aren't encountering integer overflow

        count++;
    }

    // Final assertions to verify the expected properties
    __VERIFIER_assert(count == a);

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Count: %d\n", count);

    return 0;
}