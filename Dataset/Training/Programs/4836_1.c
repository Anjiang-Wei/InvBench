#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > a); // Ensuring meaningful constraints for a and b

    int x = 1;
    int y = 2;
    int factorial = 1;

    while (x <= a) {
        factorial *= x;
        x++;
    }

    int sum = 0;
    for (int i = 0; i < b; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }

    __VERIFIER_assert(factorial > 0);
}