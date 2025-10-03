/*
  Simple Voting System Simulation
  This program simulates a simple voting system where a limited number of voters
  can vote for three candidates. The program uses assertions to ensure that
  the vote count does not exceed the number of allowed voters.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "voting_simulation.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int voters, candidate1_votes, candidate2_votes, candidate3_votes;
    int max_voters = 10;

    // Initialize votes for each candidate
    candidate1_votes = 0;
    candidate2_votes = 0;
    candidate3_votes = 0;

    // Number of voters is non-deterministic but should not exceed max_voters
    voters = __VERIFIER_nondet_int();
    assume_abort_if_not(voters >= 0 && voters <= max_voters);

    int i = 0;
    while (i < voters) {
        // Random choice of candidate
        int choice = __VERIFIER_nondet_int();
        assume_abort_if_not(choice >= 1 && choice <= 3);

        // Voting based on choice
        if (choice == 1) {
            candidate1_votes++;
        } else if (choice == 2) {
            candidate2_votes++;
        } else if (choice == 3) {
            candidate3_votes++;
        }

        i++;
        // Ensuring vote count does not exceed total voters
        __VERIFIER_assert(candidate1_votes + candidate2_votes + candidate3_votes <= voters);
    }

    // Final assertion to ensure total votes do not exceed max voters

    return 0;
}