#include <stdio.h>
#include <stdlib.h>

// This simple C program simulates a prediction game where two players choose numbers
// The player whose number is closer to a randomly chosen target wins
// The program demonstrates an iterative process of predicting numbers, calculating distances
// to a target, and determining the winner after analyzing a certain number of rounds

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

void reach_error() {
    // Custom error handling as in other examples - typically a placeholder for error conditions
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int calculate_distance(int number, int target) {
    int distance = number - target;
    if (distance < 0) {
        distance = -distance;
    }
    return distance;
}

int main() {
    unsigned int rounds = __VERIFIER_nondet_uint();
    int player1_score = 0, player2_score = 0;

    // Determine target number for the game
    int target_number = __VERIFIER_nondet_int();

    unsigned int current_round;
    for (current_round = 0; current_round < rounds; ++current_round) {
        // Each player predicts a number
        int player1_number = __VERIFIER_nondet_int();
        int player2_number = __VERIFIER_nondet_int();

        // Calculate distance to target
        int player1_distance = calculate_distance(player1_number, target_number);
        int player2_distance = calculate_distance(player2_number, target_number);

        // Determine who is closer to the target
        if (player1_distance < player2_distance) {
            player1_score++;
        } else if (player2_distance < player1_distance) {
            player2_score++;
        }
    }

    // Verify after the game that the score calculation isn't logically impossible
    __VERIFIER_assert(player1_score + player2_score <= rounds);

    // Print results - Useful for manual verification in non-automated contexts
    printf("Player 1 score: %d\n", player1_score);
    printf("Player 2 score: %d\n", player2_score);

    return 0;
}