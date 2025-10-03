#include <assert.h>
void reach_error(void) { assert(0); }

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int threshold = __VERIFIER_nondet_int();

    if (!(threshold > 0 && threshold <= 100)) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    while (x > 0) {
        sum += y;
        count++;
        x--;
    }

    assume_abort_if_not(count <= threshold);
    __VERIFIER_assert(sum == count * y);

    return 0;
}