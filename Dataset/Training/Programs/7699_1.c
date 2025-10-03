#include <assert.h>
#include <stdbool.h>
extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0 && limit <= 100);

    int counter = 0, sum = 0, square_sum = 0;

    while (1) {
        if (counter > limit) {
            break;
        }

        sum += counter;
        square_sum += counter * counter;

        if (sum > 1000) {
            break;
        }

        counter++;
    }

    __VERIFIER_assert(counter <= limit + 1);

    // Arithmetic expression check to ensure computation correctness

    return 0;
}