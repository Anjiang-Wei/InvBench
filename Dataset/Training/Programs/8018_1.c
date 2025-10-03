#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
extern void abort(void);
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

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

#define SIZE 10

int main() {
    int array[SIZE];
    int i, sum = 0, product = 1;

    // Randomly initialize the array elements
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < SIZE; i++) {
        // Assume only positive and small integers
        assume_abort_if_not(array[i] >= 0 && array[i] <= 10);

        // Compute sum and product based on some condition
        if (array[i] % 2 == 0) {
            sum += array[i];
        } else {
            product *= array[i];
        }
    }

    // Non-trivial assertion involving the computed sum and product
    // Expect that either sum or product should be greater than zero
    __VERIFIER_assert(sum > 0 || product > 0);

    return 0;
}