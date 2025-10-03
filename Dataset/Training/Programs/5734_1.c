#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n, target, i;
    int *array;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0);

    array = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(array != NULL);

    for (i = 0; i < n; ++i) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 1000); // Ensuring array elements are within a range
    }

    int sum = 0;
    int even_count = 0;

    for (i = 0; i < n; ++i) {
        sum += array[i];

        if (array[i] % 2 == 0) {
            even_count++;
        }

        if (sum > target) {
            break;
        }
    }

    if (sum <= target) {
        __VERIFIER_assert(even_count >= 0 && even_count <= n); // Ensure a meaningful property
    }

    free(array);
    return 0;
}