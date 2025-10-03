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

int __VERIFIER_nondet_int() {
    return rand() % 20; // Simulate a non-deterministic integer within range [0, 19]
}

#define LIMIT 100

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = 0;

    // Ensuring a and b are within certain bounds
    if (!(0 <= a && a <= 10 && 0 <= b && b <= 10)) {
        return 0;
    }

    // Loop that performs a certain number of iterations based on variable 'a'
    for (int i = 0; i < a; ++i) {
        c += b;
    }

    // Verification condition: the result 'c' should be equal to 'a * b'

    // Additional loop to demonstrate further complex logic
    int x = 0;
    while (x < LIMIT) {
        x += a;
        if (x > LIMIT - 10) {
            break;
        }
    }

    // Final assertion to validate that x must always be less than or equal to LIMIT
    __VERIFIER_assert(x <= LIMIT);

    return 0;
}