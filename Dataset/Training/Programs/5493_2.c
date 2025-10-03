#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 3, "reach_error"); }

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
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000);

    int i;
    int sum = 0;
    int *a = malloc(sizeof(int) * N);
    if (a == NULL) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] >= -100 && a[i] <= 100);

        sum += a[i];
        if (i % 10 == 0) {
        }
    }

    int avg = sum / N;

    int deviation = 0;
    for (i = 0; i < N; i++) {
        deviation += abs(a[i] - avg);
    }

    free(a);

    __VERIFIER_assert(deviation >= 0);

    return 0;
}