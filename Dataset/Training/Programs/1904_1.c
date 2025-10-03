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
}

int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0;
    }

    int a = 0;
    int b = 1;
    int c = 1;

    for (int i = 1; i < n; i++) {
        int temp = b;
        b += a + c;
        a = c;
        c = temp;
    }

    __VERIFIER_assert((a + b + c) >= n); // Some hypothetical meaningful constraint
    return 0;
}