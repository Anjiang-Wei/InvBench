#include <stdio.h>
#include <stdlib.h>

// Function prototypes for assertion and abort
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error(void) {
    printf("Error reached\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// A function simulating a non-deterministic integer
extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, n, sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Conditions for values a and b and ensuring a deterministic range
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    sum = 0;
    product = 1;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 20); // n can be any number between 1 and 20

    // A loop that calculates cumulative sum and product
    int counter = 0;
    while (1) {
        // Asserting conditions akin to checking loop invariants
        __VERIFIER_assert(sum == counter * a + b * counter * (counter - 1) / 2); // sum should equal sum of sequence
        __VERIFIER_assert(counter <= n);                                         // make sure `counter` does not exceed `n`

        if (!(counter < n)) {
            break;
        }

        sum += a + b * counter;
        product *= b + a;
        counter++;
    }

    // Final assertions

    return 0;
}