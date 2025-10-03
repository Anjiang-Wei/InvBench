/*
 * Integer Sequence Manipulation
 * Computes a sequence S where each element is derived based on specific conditions of previous elements.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sequence-manipulation.c", 9, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 100);

    int *S = (int *)malloc(sizeof(int) * N);
    if (S == NULL) {
        abort();
    }

    S[0] = 1; // Initial term of the sequence
    int i = 1;

    while (i < N) {
        if (S[i - 1] % 2 == 0) {
            S[i] = S[i - 1] / 2;
        } else {
            S[i] = 3 * S[i - 1] + 1;
        }

        /* This assertion checks a condition related to the sequence logic,
           but it does not explicitly indicate the loop invariant */
        __VERIFIER_assert(S[i] != 0);

        i++;
    }

    int final_result = S[N - 1];
    free(S);

    return final_result; // The final term of the sequence
}