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

extern int __VERIFIER_nondet_int();

int main() {
    int x = 0, y = 0;
    int n = __VERIFIER_nondet_int();
    int c = 0;

    if (!(n >= 0 && n < 1000)) {
        return 0;
    }

    while (x < n) {
        x++;
        y = y + 2;
        c += x * y;
    }

    if (n % 2 == 0) {
        __VERIFIER_assert((x + y) % 2 == 0);
    } else {
    }

    return 0;
}