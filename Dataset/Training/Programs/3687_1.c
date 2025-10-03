#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100);
        sum += arr[i];
    }

    int average = n > 0 ? sum / n : 0;

    int greater_than_average_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            greater_than_average_count++;
        }
    }

    __VERIFIER_assert(greater_than_average_count <= n);

    free(arr);
    return 0;
}