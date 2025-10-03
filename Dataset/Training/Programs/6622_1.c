#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    assume_abort_if_not(x > 0);
    assume_abort_if_not(y > 0);

    int a = 0;
    int b = 0;
    int c = 0;
    int i = 0;

    // Simple GCD computation logic
    while (i < 10) {
        i++;
        if (x > y) {
            a += (x - y);
            x = y;
        } else {
            b += (y - x);
            y = x;
        }

        c += x + y;
        __VERIFIER_assert(x > 0 && y > 0); // Ensures that x and y are always positive
    }

    // Verification conditions based on the modified values
    __VERIFIER_assert(a + b >= 0);

    return 0;
}