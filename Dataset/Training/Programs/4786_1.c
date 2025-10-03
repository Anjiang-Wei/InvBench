#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern unsigned int __VERIFIER_nondet_uint(void);

void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    unsigned int n, result, i;

    // Generate a non-deterministic unsigned integer
    n = __VERIFIER_nondet_uint();

    // Constrain the range of n
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 1000);

    result = 0;

    // Calculating the sum of even numbers from 1 to n
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            result += i;
        }
    }

    // Verify the final result
    __VERIFIER_assert(result % 2 == 0);

    printf("The sum of even numbers from 1 to %u is: %u\n", n, result);

    return 0;
}