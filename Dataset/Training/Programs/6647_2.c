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

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit <= 100);

    int i = 0;
    int counter = 0;
    int sum = 0;

    while (i < limit) {
        counter++;
        sum += i;
        i++;

        if (counter % 2 == 0) { // Only perform assertion every second iteration
        }
    }

    __VERIFIER_assert(i == limit);

    return 0;
}