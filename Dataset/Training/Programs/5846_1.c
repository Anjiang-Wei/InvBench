#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int N = __VERIFIER_nondet_int();
    if (N < 1) {
        return 1; // Program is not relevant if N < 1
    }
    assume_abort_if_not(N <= 1000); // Limit N to a reasonable range to avoid potential overflows and excessive computation

    int *b = (int *)malloc(sizeof(int) * N);
    int i, odd_count = 0, even_count = 0;

    for (i = 0; i < N; i++) {
        b[i] = __VERIFIER_nondet_int();
        if (b[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // The property: number of even elements + number of odd elements should be equal to N
    __VERIFIER_assert(even_count + odd_count == N);

    // Free allocated memory
    free(b);

    return 0;
}