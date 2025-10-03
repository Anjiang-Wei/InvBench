#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int max_value = __VERIFIER_nondet_int();
    int sum = 0;
    int count = 0;

    // Precondition checks
    assume_abort_if_not(max_value > 1 && max_value <= 100);

    int i = 0;
    while (1) {
        // Loop invariant here: (sum = (i*(i-1))/2) should hold

        if (!(i < max_value)) {
            break;
        }

        sum += i;
        i++;

        count++;
    }

    // Postcondition assertion
    __VERIFIER_assert(sum == (count * (count - 1)) / 2);

    return 0;
}