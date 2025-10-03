#include <stdio.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int i, x = 0, y = 10;

    for (i = 0; i < 10; i++) {
        x += 2;
        y -= 1;
    }

    // The condition below is meant to check computational logic
    if (!(x == 20 && y == 0)) {
        __VERIFIER_assert(0); // Verification check
    }

    printf("Computation complete: x = %d, y = %d\n", x, y);
    return 0;
}