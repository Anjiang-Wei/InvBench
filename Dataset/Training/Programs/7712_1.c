#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int m = 10;
    int sum_even = 0;
    int sum_odd = 0;
    int count = 0;
    int val;

    // Array to hold values for demonstration purposes
    int values[100];

    // Initialize the array with some non-deterministic values
    for (int i = 0; i < m; i++) {
        values[i] = __VERIFIER_nondet_int();
    }

    // Partition into even and odd sums
    for (int i = 0; i < m; i++) {
        val = values[i];
        if (val % 2 == 0) {
            sum_even += val;
        } else {
            sum_odd += val;
        }
        count++;
    }

    // Check an invariant condition: the count should match m after the loop
    __VERIFIER_assert(count == m);

    return 0;
}