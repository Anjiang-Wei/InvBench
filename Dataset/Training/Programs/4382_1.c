#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "matrix_sum.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
    }
    }
    return;
}

#define N 100

int main() {
    int matrix[N][N];
    int target_sum;
    int i, j;

    target_sum = __VERIFIER_nondet_int();
    assume_abort_if_not(target_sum > 0);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = __VERIFIER_nondet_int();
            assume_abort_if_not(matrix[i][j] >= 0);
        }
    }

    int cumulative_sum = 0;
    int reached_boundary = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cumulative_sum += matrix[i][j];
            if (cumulative_sum >= target_sum) {
                reached_boundary = 1;
                break;
            }
        }
        if (reached_boundary) {
            break;
        }
    }

    __VERIFIER_assert(reached_boundary == 1 || cumulative_sum < target_sum);

    printf("Final cumulative sum: %d\n", cumulative_sum);
    return 0;
}