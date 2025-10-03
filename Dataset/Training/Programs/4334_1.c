#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
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

int perform_computation(int input) {
    int x = 0, y = 50;
    while (x < 100) {
        if (input == 1) {
            x += 2;
        } else if (input == 2) {
            x += 3;
        } else if (input == 3) {
            x += 5;
        } else if (input == 4) {
            x += 7;
        } else {
            x += 1;
        }

        if (x > y) {
            y += 10;
        }
    }
    return y;
}

int main() {
    int input;
    input = __VERIFIER_nondet_int();
    if (input < 1 || input > 4) {
        return -1;
    }

    int result = perform_computation(input);

    __VERIFIER_assert(result >= 50 && result <= 150);

    return 0;
}