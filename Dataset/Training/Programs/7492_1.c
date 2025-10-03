#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

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
    int c = __VERIFIER_nondet_int();
    if (!(a > 0 && b < 100)) {
        return 0;
    }

    c = 0;
    int original_a = a;

    while (a > 0) {
        a--;
        if (c < 50) {
            c += 2;
        }
        if (a <= b) {
            break;
        }
    }

    __VERIFIER_assert((original_a <= b && c >= 0) || (original_a > b && c <= 50));

    printf("a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}