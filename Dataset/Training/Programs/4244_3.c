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
    int a, b, n;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    if (!(n >= 0 && n <= 100)) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int counter = 0;

    while (__VERIFIER_nondet_bool()) {

        if (counter >= n) {
            break;
        }

        sum += a;
        product *= b;
        counter++;
    }

    __VERIFIER_assert(sum == counter * a);

    return 0;
}