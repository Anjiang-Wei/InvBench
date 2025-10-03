#include <stdlib.h>

/* Functions that simulate external verifier interface */
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int x = 0;
    int y = 0;

    // Assuming some conditions on m and n
    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    // A loop performing a computation
    while (x < m || y < n) {
        if (x < m) {
            x = x + 1;
        }
        if (y < n) {
            y = y + 1;
        }
    }

    // Verify resulting conditions after loop
    __VERIFIER_assert(y == n);

    return 0;
}