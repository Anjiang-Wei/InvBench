#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }
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

extern int __VERIFIER_nondet_int(void);

#define MAX_BOUND 50

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= MAX_BOUND);
    assume_abort_if_not(b >= 0 && b <= MAX_BOUND);
    assume_abort_if_not(c >= 0 && c <= MAX_BOUND);
    assume_abort_if_not(a + b + c > 0);

    int sum = 0;

    if (a % 2 == 0 && b % 2 == 0) {
        while (c > 0) {
            c--;
            sum += b;
        }
    } else if (a % 2 != 0 && b % 2 != 0) {
        while (c > 0) {
            c--;
            sum += a;
        }
    } else {
        while (c > 0) {
            c--;
            sum += (a + b) / 2;
        }
    }

    __VERIFIER_assert(sum >= 0);
    return 0;
}