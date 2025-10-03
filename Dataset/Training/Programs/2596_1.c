#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    int sumOfSquares = 0;
    int i = 0;

    // Assume starting condition
    assume_abort_if_not(x >= 0 && y >= 0 && z > 0);

    // Iterate 'z' times
    while (i < z) {
        sumOfSquares += (x * x) + (y * y); // maintain sum of x^2 and y^2
        x += 1;                            // Increase x by 1
        y += 2;                            // Increase y by 2
        i++;
    }

    // We should verify that sumOfSquares remains non-negative
    __VERIFIER_assert(sumOfSquares >= 0);

    return 0;
}