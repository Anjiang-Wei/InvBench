#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
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

#define MAX_VALUE 1000

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    if (x < 0 || y < 0 || z < 0 || x >= MAX_VALUE || y >= MAX_VALUE || z >= MAX_VALUE) {
        return 0;
    }

    int a[3];
    a[0] = x;
    a[1] = y;
    a[2] = z;

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        sum += (a[i] * a[i]);
    }

    __VERIFIER_assert(sum <= (x + y + z) * (x + y + z) - a[2] * a[2]);
    return 0;
}