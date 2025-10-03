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
    return;
}

int process(int a, int b) {
    if (a < 0) {
        return b;
    } else {
        return process(a - 2, b + 2);
    }
}

int main(void) {
    int x = 20;
    int y = 0;
    int result = process(x, y);

    // The loop simulates a computational task, here counting down from a certain limit
    int limit = 100;
    int i = 0;
    while (i < limit) {
        i += 10;
    }

    // Post-conditions to be verified
    __VERIFIER_assert(i == limit);

    return 0;
}