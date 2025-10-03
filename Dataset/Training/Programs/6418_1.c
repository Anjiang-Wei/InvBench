#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern void assume_abort_if_not(int cond) {
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

int __VERIFIER_nondet_int(void);

int global_counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0;
    }

    int countA = 0, countB = 0, factor = 1;
    int *values = (int *)malloc(n * sizeof(int));

    assume_abort_if_not(values != 0);

    for (int i = 0; i < n; i++) {
        values[i] = i * factor;
        if (values[i] % 2 == 0) {
            countA++;
        } else {
            countB++;
        }
        global_counter++;
        __VERIFIER_assert(values[i] / 2 == i / 2);
    }

    for (int i = 0; i < n; i++) {
        if ((i % 3) == 0) {
            factor++;
            values[i] *= factor;
        }
    }

    for (int i = 0; i < n; i++) {
        if (values[i] % 2 == 0) {
            countA--;
        } else {
            countB--;
        }
        global_counter++;
    }

    free(values);

    return 0;
}