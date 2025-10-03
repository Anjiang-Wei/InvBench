#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Precondition
    if (!(x >= 0 && y >= 0)) {
        return 0;
    }

    int sum = 0;

    while (x > 0 && y > 0) {
        if (__VERIFIER_nondet_bool()) {
            sum += x;
            x--;
        } else {
            sum += y;
            y--;
        }
    }

    int z = __VERIFIER_nondet_int();
    int product = 1;

    while (z > 0) {
        product *= 2;
        z--;
    }

    __VERIFIER_assert(sum >= 0);

    return 0;
}