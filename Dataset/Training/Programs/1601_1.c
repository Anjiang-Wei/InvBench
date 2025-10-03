#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
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
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int x = 0;
    int y = 0;
    int z = __VERIFIER_nondet_int();

    assume_abort_if_not(z >= 0 && z <= 100);

    while (1) {
        __VERIFIER_assert(x >= 0 && y >= 0 && z >= 0);

        if (__VERIFIER_nondet_bool()) {
            if (x < z) {
                x++;
            } else if (y < z) {
                y++;
            } else {
                break;
            }
        } else {
            if (x > 0) {
                x--;
            } else if (y > 0) {
                y--;
            }
        }
    }

    return 0;
}