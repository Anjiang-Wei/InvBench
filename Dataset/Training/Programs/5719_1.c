#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
int __VERIFIER_nondet_int(void);
_Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    // Ensure sum is initially less than product of a and b
    assume_abort_if_not(sum < a * b);

    // The loop will try to increase 'sum' without surpassing 'a * b'
    while (__VERIFIER_nondet_bool()) {
        if (sum + a <= a * b) {
            sum += a;
        } else if (sum + b <= a * b) {
            sum += b;
        } else {
            break;
        }
    }

    // Verification condition
    __VERIFIER_assert(sum <= a * b);

    return 0;
}