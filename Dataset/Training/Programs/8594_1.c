#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  A program that explores the relationship between two variables x and y.
  The loop adjusts these variables based on certain conditions and verifies
  a postcondition relating x and y.
*/
int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (!(x >= 0 && y >= 0 && y <= 50 && x <= 100)) {
        return 0;
    }

    while (x < 100 && y > 0) {
        if (x % 2 == 0) {
            y = y - 1;
        } else {
            x = x + 3;
        }
        if (__VERIFIER_nondet_bool()) {
            x = x / 2;
            y = y + 2;
        }
    }

    // Ensure x is greater than or equal to y
    __VERIFIER_assert(x >= y);

    return 0;
}