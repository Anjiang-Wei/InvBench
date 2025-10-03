#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000);

    int *array = (int *)malloc(N * sizeof(int));
    int threshold = __VERIFIER_nondet_int();
    assume_abort_if_not(threshold > 0);

    int i, sum = 0, count = 0;

    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0);

        if (array[i] >= threshold) {
            sum += array[i];
            count++;
        }
    }

    if (count == 0) {
        // If no elements were above the threshold, set sum to -1 to indicate error
        sum = -1;
    }

    // The assertion checks that the sum is either -1 or a valid sum of elements
    // greater than or equal to the threshold
    __VERIFIER_assert(sum == -1 || sum >= count * threshold);

    free(array);
    return 0;
}