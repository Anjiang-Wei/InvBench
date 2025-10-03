#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "solver.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR:
        reach_error();
    }
}

int main() {
    int n, target, i, sum;
    n = __VERIFIER_nondet_int();
    target = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0);
    assume_abort_if_not(target >= n);

    int *array = (int *)malloc(sizeof(int) * n);
    assume_abort_if_not(array != NULL);

    // Initialize the array
    for (i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    sum = 0;
    for (i = 0; i < n; ++i) {
        sum += array[i];
    }

    // Perturbation: modify the array trying to make the sum exactly `target`.
    for (i = 0; i < n && sum != target; ++i) {
        if (sum < target) {
            array[i] += target - sum;
            sum = target;
        } else if (sum > target) {
            array[i] -= sum - target;
            sum = target;
        }
    }

    __VERIFIER_assert(sum == target);

    free(array);
    return 0;
}