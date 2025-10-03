#include <assert.h>
#include <stdbool.h>

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
    int c = __VERIFIER_nondet_int();

    if (!(a > 0 && b > 0)) {
        return 0; // Initial constraints
    }

    while (c < 100) {
        if (a % 2 == 0) { // If 'a' is even
            a += 3;
            b -= 2;
        } else { // If 'a' is odd
            a -= 5;
            b += 4;
        }

        c += 10;
        if (c > 50 && __VERIFIER_nondet_bool()) {
            break;
        }
    }

    __VERIFIER_assert(c >= 100 || (a + b) > 0); // Post-condition check

    return 0;
}