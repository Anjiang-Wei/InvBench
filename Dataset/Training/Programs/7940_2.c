#include <stdio.h>
#include <stdlib.h>

/*
  An example C program that simulates a simple voting system.
  The program collects votes, counts them, and verifies the integrity of the votes.
  It makes use of nondeterministic values for input and simulates constraints similar
  to the other examples.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "vote_system.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void) {
    return rand() % 2;
}

int __VERIFIER_nondet_uint(void) {
    return rand() % 100;
}

int main() {
    unsigned int MAX_VOTES = __VERIFIER_nondet_uint(); // Total number of possible votes
    unsigned int A_votes = 0, B_votes = 0;             // Votes for each candidate
    unsigned int total_votes = 0;                      // Total collected votes

    // Ensure there are at least some votes to process
    if (MAX_VOTES < 1) {
        MAX_VOTES = 1;
    }

    unsigned int i;
    for (i = 0; i < MAX_VOTES; i++) {
        int vote = __VERIFIER_nondet_int();
        if (vote == 0) {
            A_votes++;
        } else {
            B_votes++;
        }
        total_votes++;

        // Check integrity after every vote
    }

    // Final verification checks
    __VERIFIER_assert(A_votes + B_votes == MAX_VOTES);

    printf("Candidate A: %u votes\n", A_votes);
    printf("Candidate B: %u votes\n", B_votes);

    return 0;
}