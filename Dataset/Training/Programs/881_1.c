#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Ensure the precondition
    if (!(a > 0 && b > 0 && c == 0)) {
        return 0;
    }

    // Use a loop with a constraint
    while (c < 100) {
        a -= 2;
        b += 1;
        c = a + b;

        if (a < 0) {
            break;
        }
    }

    // Postcondition to verify
    __VERIFIER_assert(c >= 0);

    return 0;
}