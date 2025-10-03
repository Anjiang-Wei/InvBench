#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

#define LIMIT 1000 // Maximum limit for variable `a` to avoid infinite loop

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition: a and b are both non-negative
    if (a < 0 || b < 0) {
        return 0;
    }

    int sum = 0;
    int iterations = 0;

    while (a > 0 && iterations < LIMIT) {
        if (a % 2 == 0) {
            sum += b;
        }
        a--;
        iterations++;
    }

    __VERIFIER_assert(sum >= 0);

    return 0;
}