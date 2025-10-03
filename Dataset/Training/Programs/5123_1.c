#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int a = 0;
    int b = 0;
    int c = 0;

    if (!(n > 0 && m > 0 && n == m)) {
        return 0;
    }

    // Random logic to increment values
    while (a < n) {
        a++;
        b += 2;     // b is always twice of a
        c += a + b; // accumulate a and b

        if (c > 1000) {
            break; // arbitrary break condition
        }
    }

    // Check if b is correctly twice of a
    __VERIFIER_assert(b == 2 * a);

    // Check if the random accumulation logic is consistent
    if (a < n) {
    } else {
    }

    printf("Computation completed successfully\n");
    return 0;
}