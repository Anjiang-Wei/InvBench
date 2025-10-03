#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
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
    int prod = 1;
    int counter = 0;

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    while (__VERIFIER_nondet_bool() && counter < 10) {
        sum += a;
        prod *= b;
        counter++;

        if (prod > 1000) {
            break;
        }
    }

    int expected_sum;
    if (counter < 10) {
        expected_sum = a * counter;
    } else {
        expected_sum = a * 10;
    }

    __VERIFIER_assert(sum == expected_sum);

    return 0;
}