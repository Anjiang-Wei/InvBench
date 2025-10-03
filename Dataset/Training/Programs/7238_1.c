#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
   In this program, we are implementing a simple number sequence generator
   that generates a sequence such that each number is the sum of the previous two numbers.
   The precondition is that the first two numbers must be non-negative.
   The postcondition is to ensure that the sequence always remains non-negative.
*/

#define MAX_SEQ 100

int main() {
    int n1, n2, current, next;
    int sequence[MAX_SEQ];
    int seq_len = __VERIFIER_nondet_int();

    // Ensure valid sequence length
    assume_abort_if_not(seq_len > 2 && seq_len < MAX_SEQ);

    n1 = __VERIFIER_nondet_int();
    n2 = __VERIFIER_nondet_int();

    // Precondition: First two numbers must be non-negative
    assume_abort_if_not(n1 >= 0 && n2 >= 0);

    // Initialize the sequence
    sequence[0] = n1;
    sequence[1] = n2;

    // Loop to generate the sequence
    for (int i = 2; i < seq_len; i++) {
        current = sequence[i - 1] + sequence[i - 2];

        // Ensure current remains non-negative to validate our logic
        __VERIFIER_assert(current >= 0);

        sequence[i] = current;
    }

    // Output the sequence for visualization
    printf("Generated Sequence: ");
    for (int i = 0; i < seq_len; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    return 0;
}