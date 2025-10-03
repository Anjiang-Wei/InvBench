#include <assert.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);
    assume_abort_if_not(z >= 0 && z <= 100);

    int sum = 0;
    int product = 1;

    int limit = 100; // You can set your limits

    while (x > 0 && y > 0 && z > 0 && limit > 0) {
        if (x % 2 == 0) {
            sum += x;
        } else {
            sum += y;
        }

        if (z % 2 == 1) {
            product *= z;
        }

        x--;
        y--;
        z--;
        limit--;
    }

    // Assume some meaningful properties to assert
    __VERIFIER_assert(sum >= 0);

    return 0;
}