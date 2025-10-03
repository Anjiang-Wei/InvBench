#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "proposed_program.c", 5, "reach_error");
}

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

extern int __VERIFIER_nondet_int(void);
void *malloc(size_t size);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int *sequence = (int *)malloc(sizeof(int) * N);
    if (sequence == NULL) {
        abort();
    }

    int i;
    int even_count = 0;

    for (i = 0; i < N; i++) {
        sequence[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < N; i++) {
        if (sequence[i] % 2 == 0) {
            even_count++;
        }
    }

    // Check if the count of even numbers is less than or equal to N
    __VERIFIER_assert(even_count <= N);

    free(sequence);
    return 0;
}