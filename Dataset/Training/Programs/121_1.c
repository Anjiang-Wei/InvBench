#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define LIMIT 100

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int counter = __VERIFIER_nondet_int();

    // Initialize variables
    int sum = a;
    int product = b == 0 ? 1 : b; // Prevent product being initialized to zero
    counter = 0;

    // Loop that will modify and test the sum and product
    while (__VERIFIER_nondet_bool()) {
        if (counter >= LIMIT) {
            break;
        }

        // If counter is even, add to sum, else multiply
        if (counter % 2 == 0) {
            int addend = __VERIFIER_nondet_int();
            sum += addend;
        } else {
            int factor = __VERIFIER_nondet_int();
            product *= factor;
        }

        counter++;
    }

    // After the loop, assert that the counter never exceeded the limit
    __VERIFIER_assert(counter <= LIMIT);
    // Additional assertions for meaningful conditions related to sum/product

    return 0;
}