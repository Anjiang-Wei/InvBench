#include <assert.h>
#include <stdio.h>

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
    int limit = __VERIFIER_nondet_int();

    if (!(limit > 0)) {
        return 0;
    }
    if (a <= 0 || b <= 0) {
        return 0;
    }

    int sum = 0;
    int steps = 0;

    while (sum < limit) {
        if (__VERIFIER_nondet_bool()) {
            sum += a;
        } else {
            sum += b;
        }
        steps++;

        if (sum > limit) {
            break;
        }
    }

    __VERIFIER_assert(sum >= limit);
    printf("Sum: %d, Steps: %d\n", sum, steps);

    return 0;
}