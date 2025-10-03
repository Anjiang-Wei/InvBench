#include <assert.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

#define LIMIT 1000

int main() {
    int x = __VERIFIER_nondet_int();
    int y = 1;

    // Precondition: Start with a positive x less than LIMIT
    if (!(x > 0 && x < LIMIT)) {
        return 0;
    }

    while (x != 0) {
        // If x is odd, multiply y by x; if even, halve x
        if (x % 2 == 1) {
            y *= x;
            x -= 1;
        } else {
            x /= 2;
        }

        // Ensure y doesn't overflow for the sake of this example
        if (y <= 0 || y >= LIMIT) {
            break;
        }
    }

    // Check that y is strictly positive if we didn't break due to overflow
    if (x == 0) {
        __VERIFIER_assert(y > 0);
    }

    return 0;
}