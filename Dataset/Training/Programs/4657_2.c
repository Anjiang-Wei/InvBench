#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (!(a >= 0 && b >= 0 && n > 0)) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    while (count < n) {
        _Bool inc_a = __VERIFIER_nondet_bool();

        if (inc_a) {
            a++;
        } else {
            b++;
        }

        sum += a + b;
        count++;
    }

    __VERIFIER_assert(count == n);

    return 0;
}