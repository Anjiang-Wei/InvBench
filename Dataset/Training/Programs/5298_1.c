// Your complete C program here

#include <assert.h>
#include <stdlib.h>

// This is a verification program where we will calculate two sequences
// and check properties relating to their sums and relations.

// Function to mimic nondeterministic integer generation
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

typedef struct sequence_node {
    int value;
    struct sequence_node *next;
} *Sequence;

void abort_program() {
    while (1) {
    } // Infinite loop to mimic abort behavior
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort_program();
    }
    }
}

int main() {
    int sequence_length = __VERIFIER_nondet_int();
    if (!(sequence_length >= 0 && sequence_length <= 100)) {
        return 0; // Limit the length
    }

    Sequence seq_a = (Sequence)malloc(sizeof(struct sequence_node));
    Sequence seq_b = (Sequence)malloc(sizeof(struct sequence_node));

    if (seq_a == NULL || seq_b == NULL) {
        abort_program();
    }

    Sequence p_a = seq_a;
    Sequence p_b = seq_b;

    int sum_a = 0;
    int sum_b = 0;

    // Building two sequences where seq_a consists entirely of 1s and seq_b consists entirely of 2s
    while (sequence_length--) {
        p_a->value = 1;
        p_b->value = 2;

        sum_a += p_a->value;
        sum_b += p_b->value;

        // Only extend if more elements are needed
        if (sequence_length > 0) {
            p_a->next = (Sequence)malloc(sizeof(struct sequence_node));
            p_b->next = (Sequence)malloc(sizeof(struct sequence_node));
            if (p_a->next == NULL || p_b->next == NULL) {
                abort_program();
            }
        } else {
            p_a->next = NULL;
            p_b->next = NULL;
        }

        p_a = p_a->next;
        p_b = p_b->next;
    }

    // Safety proof: sum_b should be twice of sum_a since sequence b consists of 2s only
    __VERIFIER_assert(sum_b == 2 * sum_a);

    // Free the allocated memory
    p_a = seq_a;
    while (p_a != NULL) {
        Sequence tmp = p_a;
        p_a = p_a->next;
        free(tmp);
    }

    p_b = seq_b;
    while (p_b != NULL) {
        Sequence tmp = p_b;
        p_b = p_b->next;
        free(tmp);
    }

    return 0;
}