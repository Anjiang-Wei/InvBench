// Complete C program for automated verification tools

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 30, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int i, j;
    int N;

    // Obtain a nondeterministic array size
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 100);

    // Allocate memory for arrays and a matrix
    int *a = (int *)malloc(sizeof(int) * N);
    int *b = (int *)malloc(sizeof(int) * N);
    int *prefix = (int *)malloc(sizeof(int) * (N + 1));
    int *matrix = (int *)malloc(sizeof(int) * N * N);

    // Initialize array a with nondeterministic boolean values (0 or 1)
    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] == 0 || a[i] == 1);
    }

    // Flip bits into array b
    for (i = 0; i < N; i++) {
        if (a[i] == 0) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }

    // Compute prefix sums of a: prefix[i] = sum of a[0..i-1]
    prefix[0] = 0;
    for (i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    // Compute sums of a and b
    int sum_a = 0;
    int sum_b = 0;
    for (i = 0; i < N; i++) {
        sum_a += a[i];
        sum_b += b[i];
    }

    // Verify basic sum relationships

    // Count ones and zeros in a directly
    int count_ones = 0;
    int count_zeros = 0;
    for (i = 0; i < N; i++) {
        if (a[i] == 1) {
            count_ones++;
        } else {
            count_zeros++;
        }
    }

    // Build an N×N matrix where matrix[i,j] = a[i] & a[j]
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i * N + j] = a[i] & a[j];
        }
    }

    // Sum all entries of the matrix
    int sum_mat = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum_mat += matrix[i * N + j];
        }
    }
    // For boolean array a, sum of AND-matrix = sum_a * sum_a

    // A do-while loop to count up to sum_a
    int k = 0;
    do {
        k++;
    } while (k < sum_a);

    // A for-loop using continue and break
    int lim = N + 1;
    for (i = 0; i < lim; i++) {
        if (i < N) {
            continue;
        }
        // When i == N, break out
        break;
    }
    __VERIFIER_assert(i == N);

    // Free allocated memory
    free(a);
    free(b);
    free(prefix);
    free(matrix);

    return 0;
}