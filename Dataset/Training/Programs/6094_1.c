#include <assert.h>
#include <stdbool.h>
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
}
_Bool __VERIFIER_nondet_bool();

int main() {
    int x = 0;
    int y = 0;
    int counter = 0;

    while (counter < 100) {
        if (__VERIFIER_nondet_bool()) {
            if (x < 50) {
                x += 1;
            } else {
                x -= 1;
            }
        } else {
            if (y < 50) {
                y += 1;
            } else {
                y -= 1;
            }
        }
        counter += 1;
    }

    // Validate that x and y are within expected range
    __VERIFIER_assert(x >= 0 && x <= 50);

    // Simple checksum constraint as a logical property
    int checksum = x + 2 * y;

    return 0;
}