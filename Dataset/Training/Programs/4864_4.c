#include <assert.h>
#include <stdio.h>

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
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x, y, z;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(x > 0);
    assume_abort_if_not(y > 0);
    assume_abort_if_not(z >= 0);

    int threshold = x + y + z; // A threshold value for loop termination
    int count = 0;

    while (count < threshold) {
        if (__VERIFIER_nondet_bool()) {
            if (x > y) {
                x = x - y;
            } else {
                y = y - x;
            }
        } else {
            z = z + 1;
            if (z == threshold) {
                break;
            }
        }
        count++;
    }

    __VERIFIER_assert(x >= 0 && y >= 0 && z <= threshold);

    return 0;
}