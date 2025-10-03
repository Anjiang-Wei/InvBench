#include <stdio.h>
#include <stdlib.h>

void reach_error(void) {
    printf("Error reached\n");
    exit(1);
}

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
    int sum = 0, diff = 0;

    if (!(a != b && a >= 0 && b >= 0)) {
        return 0;
    }

    while (a > 0 && b > 0) {
        if (__VERIFIER_nondet_bool()) {
            sum += a;
            a--;
        } else {
            diff -= b;
            b--;
        }
    }

    __VERIFIER_assert((sum >= 0) || (diff <= 0));
    printf("Computation completed: sum = %d, diff = %d\n", sum, diff);
    return 0;
}