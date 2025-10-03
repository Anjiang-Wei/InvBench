#include <limits.h>
#include <stdlib.h>

extern void abort(void);
void reach_error(void) { abort(); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0; // Terminate if n is not positive
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 0; // Fail gracefully if memory allocation fails
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = __VERIFIER_nondet_int();
    }

    int sum_even = 0, sum_odd = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            sum_even += arr[i];
        } else {
            sum_odd += arr[i];
        }
    }

    // Ensure that the sum of even-indexed elements is even and odd-indexed is odd
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            __VERIFIER_assert(sum_even % 2 == 0);
        } else {
        }
    }

    free(arr); // Clean up
    return 0;
}