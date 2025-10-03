#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int M = __VERIFIER_nondet_int();

    assume_abort_if_not(M >= 1 && M <= 10);

    int i = 0, counter_odd = 0, counter_even = 0;

    while (i < M * 4) {
        if (i % 2 == 0) {
            // Increment the even counter for every even i value up to 4*M times
            counter_even++;
        } else {
            // Increment the odd counter for every odd i value up to 4*M times
            counter_odd++;
        }
        i++;
    }

    // Confirm that counter_even and counter_odd are correctly counted based on their iterations
    __VERIFIER_assert(counter_even == 2 * M);

    return 0;
}