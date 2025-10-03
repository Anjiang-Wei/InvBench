#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() {}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main(void) {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (!(x > 10 && y > 10)) {
        return 0;
    }

    int k = 0;
    while (x > 0 && y > 0) {
        if (__VERIFIER_nondet_bool()) {
            x -= 3;
            k += 2;
        } else {
            y -= 2;
            k += 1;
        }
    }

    // Final condition to check after loop
    __VERIFIER_assert(k >= 0);
    // Additional constraint: either x or y must be <= 0 to ensure loop exit

    printf("k = %d\n", k); // Output the final value of k

    return 0;
}