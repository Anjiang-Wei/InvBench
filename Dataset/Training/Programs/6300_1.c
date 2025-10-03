/*
 * New Program: Exploring Dynamics and Invariants in an Iterative System
 * Author: OpenAI15
 * Description: This program computes sequences and performs checks based on dynamically calculated constraints.
 */

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 1000) {
        return 0;
    }

    int *seq = (int *)malloc(n * sizeof(int));
    int *cum_sum = (int *)malloc(n * sizeof(int));

    if (!seq || !cum_sum) {
        abort();
    }

    seq[0] = 1;     // Base value of seq
    cum_sum[0] = 1; // Sum the first element

    for (int i = 1; i < n; i++) {
        seq[i] = seq[i - 1] + (i % 2 == 0 ? i : 2 * i); // Generate sequence with varying growth rate
        cum_sum[i] = cum_sum[i - 1] + seq[i];           // Compute cumulative sum

        // Using different numerical relationships to demonstrate the constraint analysis
        __VERIFIER_assert(seq[i] > 0);
    }

    free(seq);
    free(cum_sum);
    return 1;
}