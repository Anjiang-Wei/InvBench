#include <assert.h>
#include <stdlib.h>

extern void abort(void);
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

int main() {
    int a = 0;
    int b = 100;
    int limit = 200;
    while (a < limit) {
        a += 2;
        b += 2;
        __VERIFIER_assert(a <= b);
    }

    // Ensure that a and b follow the same pattern

    return 0;
}