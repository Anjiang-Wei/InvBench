#include <stdio.h>
#include <stdlib.h>
extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    assume_abort_if_not(b >= 1 && b <= 5);
    assume_abort_if_not(n >= 0 && n <= 10);

    int i, x, y;

    x = 1;
    y = b;

    for (i = 0; i < n; i++) {

        if (y % 2 == 0) {
            x *= 2;
        } else {
            x += y;
        }

        y++;
    }

    // Verify some properties of the computation
    __VERIFIER_assert(y == b + n);

    printf("Computation finished, x: %d, y: %d\n", x, y);
    return 0;
}