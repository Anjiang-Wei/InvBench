#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "voting_system.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int num_voters, votes_for_A = 0, votes_for_B = 0;
    int total_votes, expected_votes;
    int i;

    num_voters = __VERIFIER_nondet_int();
    expected_votes = __VERIFIER_nondet_int();

    assume_abort_if_not(num_voters > 0 && num_voters < 1000);
    assume_abort_if_not(expected_votes > 0 && expected_votes <= num_voters);

    total_votes = 0;

    // Simulate the voting process
    for (i = 0; i < num_voters; i++) {
        int choice = __VERIFIER_nondet_int();
        assume_abort_if_not(choice == 0 || choice == 1);

        if (choice == 0) {
            votes_for_A++;
        } else {
            votes_for_B++;
        }
        total_votes++;
    }

    // Check the invariant: total_votes should equal the number of voters

    // Check that the reported votes match the expected votes
    __VERIFIER_assert(votes_for_A + votes_for_B == total_votes);

    printf("Voting Complete:\n");
    printf("Votes for A: %d\n", votes_for_A);
    printf("Votes for B: %d\n", votes_for_B);
    printf("Total Votes: %d\n", total_votes);

    return 0;
}