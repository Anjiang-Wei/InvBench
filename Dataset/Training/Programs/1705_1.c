#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100); // Ensure n is positive and not too large

    int current = 0;
    int count = 0;
    int max_count = 0;

    while (current < n) {
        int random_value = __VERIFIER_nondet_int();
        assume_abort_if_not(random_value >= 0 && random_value <= 50);

        if (random_value % 2 == 0) { // Check if the value is even
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
            }
            count = 0;
        }
        current++;
    }

    // Ensure that max_count is never more than n
    __VERIFIER_assert(max_count <= n);

    // The program should return successfully
    return 0;
}