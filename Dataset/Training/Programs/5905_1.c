#include <assert.h>
#include <stdio.h>

void reach_error() {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        __VERIFIER_nondet_int(); // Simulating an abort
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

    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);

    if (x % 2 != 0 || y % 2 != 0) {
        return 0;
    }

    int sum = 0;
    while (__VERIFIER_nondet_bool()) {
        x += 2;
        y += 2;
        sum += 4;

        if (sum > 1000) {
            break;
        }
    }

    // Check the property at the end
    __VERIFIER_assert((x % 2 == 0) && (y % 2 == 0));

    printf("Loop ended with x: %d, y: %d, sum: %d\n", x, y, sum);
    return 0;
}