#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    unsigned int b = __VERIFIER_nondet_uint();
    unsigned int c = __VERIFIER_nondet_uint();

    if (!(a >= 0 && b >= 0 && c >= 0)) {
        return 0; // Initial constraint
    }

    unsigned int sum1 = 0;
    unsigned int sum2 = 0;

    while (b > 0 && c > 0) {
        sum1 += a;
        sum2 += 2 * a;
        b--;
        c -= 2;
    }

    __VERIFIER_assert(sum2 == 2 * sum1);
    return 0;
}