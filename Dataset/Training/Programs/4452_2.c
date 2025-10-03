#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error(void) {
    printf("Error reached\n");
    abort();
}
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int arr_size;

    assume_abort_if_not(n > 0 && n <= 500);
    assume_abort_if_not(m > 0 && m <= 500);
    arr_size = n + m;

    assume_abort_if_not(arr_size <= 1000);

    int *arr = (int *)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        abort(); // allocation failure
    }

    for (int i = 0; i < arr_size; i++) {
        arr[i] = __VERIFIER_nondet_int() % 20; // random numbers between 0 and 19
    }

    for (int i = 0; i < arr_size; i++) {
        if (i < n) {
            sum += arr[i];
        }
        if (i < m && arr[i] != 0) {
            product *= arr[i];
        }
    }

    __VERIFIER_assert(product != 0);

    free(arr);
    return 0;
}