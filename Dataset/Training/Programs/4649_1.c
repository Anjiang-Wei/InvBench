#include <assert.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    // Ensure a and b are positive
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Loop to perform addition without using the '+' operator
    int i;
    for (i = 0; i < a; i++) {
        sum++;
    }
    for (i = 0; i < b; i++) {
        sum++;
    }

    // Verify the sum is equal to a + b
    __VERIFIER_assert(sum == a + b);

    return 0;
}