/*
 * A new program inspired by the patterns and structures
 * in the example programs.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
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

int __VERIFIER_nondet_int(void);

int N;

int main() {
    N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int i;
    long long count[3] = {0, 0, 0};
    int *arr = malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int() % 10; // Initialize with random values between 0 and 9
    }

    for (i = 0; i < N; i++) {
        if (arr[i] % 3 == 0) {
            count[0]++;
        } else if (arr[i] % 3 == 1) {
            count[1]++;
        } else {
            count[2]++;
        }
    }

    long long total_count = count[0] + count[1] + count[2];
    __VERIFIER_assert(total_count == N);
    free(arr);
    return 0;
}