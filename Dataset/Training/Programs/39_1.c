extern void abort(void);
#include <assert.h>

void reach_error() { assert(0); }

extern void abort(void);
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
    return;
}

extern int __VERIFIER_nondet_int();

int main() {
    int n, i, count;
    int array[10];

    // Obtaining a nondet value in range [1, 10]
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    // Fill the array with nondet values
    for (i = 0; i < 10; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    count = 0;

    // Checking numbers greater than n in the array
    for (i = 0; i < 10; i++) {
        if (array[i] > n) {
            count++;
        }
    }

    // We assert that count is always between 0 and 10
    __VERIFIER_assert(count >= 0 && count <= 10);

    return 0;
}