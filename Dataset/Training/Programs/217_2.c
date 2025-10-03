#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "mysterious_program.c", 5, "reach_error");
}

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
    return;
}

int main() {
    int threshold = __VERIFIER_nondet_int();
    if (!(threshold > 0)) {
        return 0;
    }

    int n = __VERIFIER_nondet_int();
    int sum = 0, max_value = -1;

    if (n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int current_value = __VERIFIER_nondet_int();
        assume_abort_if_not(current_value >= 0); // We assume values are non-negative

        sum += current_value;
        if (current_value > max_value) {
            max_value = current_value;
        }

        if (sum > threshold) {
            break;
        }
    }

    __VERIFIER_assert(max_value >= 0);

    printf("Final sum: %d, Maximum value: %d\n", sum, max_value);

    return 0;
}