#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    int a = 0, b = 1;
    int i;

    // Compute Fibonacci sequence up to the n-th number
    for (i = 0; i < n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    __VERIFIER_assert(a > 0); // Fibonacci numbers (except the first few) are positive

    return 0;
}