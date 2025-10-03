#include <assert.h>
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        __VERIFIER_nondet_bool();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int counter = 0;

    assume_abort_if_not(a >= 0 && b >= 0);

    while (__VERIFIER_nondet_bool()) {
        sum += counter;
        product *= (counter + 1);
        if (counter >= a + b) {
            break;
        }
        counter++;
    }

    for (int i = 0; i < sum; i++) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            sum -= i;
        }
    }

    __VERIFIER_assert(sum >= 0);

    return 0;
}