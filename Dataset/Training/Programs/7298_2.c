#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int i = 0;
    int process_value = 0;
    int prior_value = 0;
    int final_count = 0;

    if (n <= 0) {
        return 0;
    }

    assume_abort_if_not(n < 1000); // Assumption to avoid overly large inputs.

    while (i < n) {
        int current_value = __VERIFIER_nondet_int();

        if (current_value % 2 == 0) {
            process_value += current_value;
            final_count++;
        }

        if (i % 10 == 9) {
            prior_value = process_value;
        }

        i++;
    }

    __VERIFIER_assert(final_count <= n);
    return 0;
}