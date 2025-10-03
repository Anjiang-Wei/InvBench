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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int count = 0;

    // Assume initial constraints
    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y > 0 && y <= 10);

    // A loop to perform an arbitrary computational logic
    while (__VERIFIER_nondet_bool()) {
        if (count >= y) {
            break;
        }

        // Modify x in a pseudo-random manner
        if (x % 2 == 0) {
            x += 3;
        } else {
            x -= 2;
        }

        if (x < 0) {
            x = 0;
        } else if (x > 100) {
            x = 100;
        }

        count++;
    }

    // Postcondition: ensure x is within the expected bounds
    __VERIFIER_assert(x >= 0 && x <= 100);

    return 0;
}