#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int counter = 0;

    while (counter < 10) {
        sum += counter;
        product *= (counter + 1);

        // Some arbitrary condition for the demonstration
        if (sum > n) {
            break;
        }

        counter++;
    }

    // Check some conditions at the end of the loop
    if (counter >= 10) {
        __VERIFIER_assert(sum >= 0);
    }

    return 0;
}